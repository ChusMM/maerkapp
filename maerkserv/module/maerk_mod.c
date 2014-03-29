/* Module features: chardevices management with ioctl, DMA using ioremap and ioread/write, 
   interruption handling, and delayed workqueues management. 
   J.Manuel Muñoz */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/string.h>
#include <asm/uaccess.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <asm/io.h>
#include <linux/cdev.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/platform_device.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#define MOD_DESC   "Märklin digital Linux device-driver"
#define MOD_AUTHOR "J.Manuel Muñoz"
#define LICENSE    "GPL"

#define MY_MACIG    'G'
#define READ_IOCTL  _IOR (MY_MACIG, 0, int)
#define WRITE_IOCTL _IOW (MY_MACIG, 1, int)

#define DRIVER_NAME "intgen"
//#define HWICAP_REGS  (0x10000)
#define INTGEN_MAJOR 260
#define INTGEN_MINOR 0
#define INTGEN_DEVICES 1

//#define SRAM_MEM_BASEADDR 0xFFE00000
//#define SRAM_MEM_HIGHADDR 0xFFE000FF
#define SRAM_MEM_BASEADDR 0x91000000
#define SRAM_MEM_HIGHADDR 0x9100000C
#define SIZE SRAM_MEM_HIGHADDR - SRAM_MEM_BASEADDR

#define LOCONET_BASE 0x90000000
#define LOCONET_HIGH 0x90000004
#define LOCONET_SIZE LOCONET_HIGH - LOCONET_BASE

#define COMM_CHARDEV "command_chardev"
#define BUF_LEN 12
#define COMM_LEN BUF_LEN - 1
#define WORD_LEN 8
#define ID_LEN 2

#define BIN   "/home/root/maerkserv/server/bin/Event"
#define PWD   "PWD=/home/root/maerkserv/server/bin" 
#define HOME  "HOME=/home/root/" 
#define PATH  "PATH=/sbin:/usr/sbin:/bin:/usr/bin"
#define LDLIB "LD_LIBRARY_PATH=/lib"

/*#define BIN  "/home/napster/PFC/maerkapp/maerkserv/server/bin/Event"
#define PWD   "PWD=/home/napster/PFC/maerkapp/maerkserv/server/bin" 
#define HOME  "HOME=/home/napster/"
#define PATH  "PATH=/sbin:/usr/sbin:/bin:/usr/bin"
#define LDLIB "LD_LIBRARY_PATH=/opt/IceE-1.3.0/lib/"*/

void *io_base;
void *loconet_io_base;
static int major_com;
static char msg_com[BUF_LEN];
static void event_work_handler(struct work_struct *w);
static struct workqueue_struct *wq = 0;
static DECLARE_DELAYED_WORK(work, event_work_handler);
static unsigned long sec = 1;
static struct mutex intgen_sem;
static struct class *intgen_class;

static void event_work_handler(struct work_struct *w) {

	u32 content;
	int i, ret = 0, offset = 0;
	char loc[ID_LEN];
	char sen[ID_LEN];
	char evnt[WORD_LEN];
	char *argv[4];
	char *envp[] = {PWD, HOME, PATH, LDLIB, NULL};
	
	content = ioread32(loconet_io_base + offset);
	
	snprintf(evnt, WORD_LEN, "%08X", content);
	evnt[WORD_LEN - 1] = '\0';
	
	printk(KERN_INFO "event information: %08X \n", content);
			
	loc[i] = evnt[0];       
	sen[i] = evnt[1];
	loc[ID_LEN - 1] = '\0';
	sen[ID_LEN - 1] = '\0';

	argv[0] = BIN;
	argv[1] = (char *) loc;
	argv[2] = (char *) sen;
	argv[3] = NULL;

	printk(KERN_INFO "usermodehelper: init \n");
	
	ret = call_usermodehelper(BIN, argv, envp, UMH_WAIT_EXEC);

	if (ret != 0) {
		printk(KERN_ERR "error in call to usermodehelper: %d \n", ret);
	}
	else {
		printk(KERN_INFO "event upcall succeeded \n");
	}
}

static ssize_t com_read(struct file *filp, 
    					 char __user *buffer, 
    					 size_t length, loff_t *offset) {
	
  	return simple_read_from_buffer(buffer, length, offset, msg_com, BUF_LEN);
}

static ssize_t com_write(struct file *filp, 
    					  const char __user *buff, 
    					  size_t len, loff_t *off) {

    if(len > BUF_LEN - 1) {
		return -EINVAL;
	}
				
	copy_from_user(msg_com, buff, len);
	msg_com[len - 1] = '\0'; 
									
	return len;
}

char buf_com[BUF_LEN];
static long com_ioctl(struct file *filep, unsigned int cmd, unsigned long arg) {

	
	int op, offset;
	u32 addr_content;
	char command[COMM_LEN];
	
	switch(cmd) {

		case READ_IOCTL:

			printk(KERN_INFO "buf_com content at read: %s \n", buf_com);
			copy_to_user((char *)arg, buf_com, BUF_LEN);
			
			break;
	
		case WRITE_IOCTL:

			copy_from_user(buf_com, (char *)arg, BUF_LEN);
			printk(KERN_INFO "buf_com(char) content at write: %s \n", buf_com);

			strncpy(command, buf_com, BUF_LEN - 2);
			command[COMM_LEN - 1] = '\0';
			
			addr_content = simple_strtol(command, NULL, 0);
			printk(KERN_INFO "command extracted(u32): %08X \n", addr_content);

			op = buf_com[BUF_LEN - 2] - '0';
			printk(KERN_INFO "operation code(int): %d \n", op);

			switch(op) {
				case 1:
					offset = 0;
					break;
				case 2:
					offset = 0;//4;
					break;
				case 3:
					offset = 0;//8;
					break;
				default:
					offset = -1;
					printk(KERN_ERR "non-valid operation code \n");
					break;
			}

			if(offset >= 0) {
				iowrite32(addr_content, io_base + offset);
			}
			
			break;

		default:
			return -ENOTTY;
	}		 
	return BUF_LEN;
}

static struct file_operations fops_com = {

	.read  = com_read, 
	.write = com_write,
	.unlocked_ioctl = com_ioctl,
};

static irqreturn_t int_generator_irq_handler(int irq, void *dev_id) {

	printk(KERN_INFO "int_generator interrupt\n");
	
	if (wq) {	
		queue_delayed_work(wq, &work, sec);
	}
	
	return IRQ_HANDLED;
}

static int __devinit intgen_of_probe(struct platform_device *op, void *config) {
	
	struct resource res;
	const unsigned int *id;
	const char *family;
	int rc;
	int irq;
	int result;
	const struct config_registers *regs;


	rc = of_address_to_resource(op->dev.of_node, 0, &res);
	if (rc) {
		dev_err(&op->dev, "invalid address\n");
		return rc;
	}

	irq = of_irq_to_resource(op->dev.of_node, 0, &res);
	if (irq == NO_IRQ) {
	  dev_err(&op->dev, "no irq detected\n");
	  return -ENODEV;
	}
	else {
	  dev_info(&op->dev, "irq %d\n", irq);
	}

	result = request_irq(irq, int_generator_irq_handler, 0, "intgen", NULL);
	if (result < 0)  {
	  printk(KERN_ERR "unable to request IRQ %d : %d \n", irq, result);
	  return -ENODEV;
	}

	return 0;
}

static const struct of_device_id __devinitconst intgen_of_match[];
static int __devinit intgen_drv_probe(struct platform_device *pdev) {

	const struct of_device_id *match;
	struct resource *res;
	//const struct config_registers *regs;

	printk(KERN_INFO "intgen_drv_probe in\n");   

	match = of_match_device(intgen_of_match, &pdev->dev);

	if (match) {
		printk(KERN_INFO "intgen matches\n"); 
		return intgen_of_probe(pdev, match->data);
  	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	if (!res) {
		printk(KERN_INFO "intgen no resource\n"); 
		return -ENODEV;
	}
	
	printk(KERN_INFO "intgen_drv_probe out\n");
}

static int __devexit intgen_drv_remove(struct platform_device *pdev) {
	//return hwicap_remove(&pdev->dev);
}

/* Match table for device tree binding */
static const struct of_device_id __devinitconst intgen_of_match[] = {
	{ .compatible = "xlnx,int-generator-1.01.a"},
	{},
};
MODULE_DEVICE_TABLE(of, intgen_of_match);

static struct platform_driver intgen_platform_driver = {
	.probe = intgen_drv_probe,
	.remove = intgen_drv_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = DRIVER_NAME,
		.of_match_table = intgen_of_match,
	},
};

static int __init maerk_module_init(void) {

	int retval;
	dev_t devt;
	
	major_com = register_chrdev(0, COMM_CHARDEV, &fops_com);

	if(major_com < 0) {
     	printk(KERN_ERR "chardevice registration failed: %d\n", major_com);
		return major_com;
	}
	
	printk(KERN_INFO "maerk_mod: major number assigned: %d \n", major_com);
	printk(KERN_INFO "create node with mknod /dev/%s c %d 0\n", COMM_CHARDEV, major_com);
	
	if (!wq) {	
		wq = create_singlethread_workqueue("wq");
	}
	
	io_base = ioremap(SRAM_MEM_BASEADDR, SIZE);
	loconet_io_base = ioremap(LOCONET_BASE, LOCONET_SIZE);

	intgen_class = class_create(THIS_MODULE, "intgen");
	mutex_init(&intgen_sem);

	devt = MKDEV(INTGEN_MAJOR, INTGEN_MINOR);
	retval = register_chrdev_region(devt, INTGEN_DEVICES, DRIVER_NAME);

	if (retval < 0) {
		return retval;
	}

	retval = platform_driver_register(&intgen_platform_driver);

	if (retval) {
		goto failed;
	}
	return retval;

	failed:
		unregister_chrdev_region(devt, INTGEN_DEVICES);
		return retval;
}

static void __exit maerk_module_exit(void) {

	dev_t devt = MKDEV(INTGEN_MAJOR, INTGEN_MINOR);
	
	unregister_chrdev(major_com, COMM_CHARDEV);
	printk(KERN_INFO "chardevice for %s unregistered\n", COMM_CHARDEV);

	if (wq) {
		destroy_workqueue(wq);
	}
	
	class_destroy(intgen_class);

	platform_driver_unregister(&intgen_platform_driver);

	unregister_chrdev_region(devt, INTGEN_DEVICES);
}  

module_init(maerk_module_init);
module_exit(maerk_module_exit);

MODULE_LICENSE     (LICENSE);
MODULE_DESCRIPTION (MOD_DESC);
MODULE_AUTHOR      (MOD_AUTHOR);
