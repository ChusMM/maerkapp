# Linux device driver Makefile
# make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
# make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

obj-m += maerk_mod.o
KDIR = /home/napster/uclinux/linux-2.6-xlnx/

all:
	make ARCH=powerpc CROSS_COMPILE=powerpc-4xx-softfloat- -C $(KDIR) M=$(PWD) modules

clean:
	make ARCH=powerpc CROSS_COMPILE=powerpc-4xx-softfloat- -C $(KDIR) M=$(PWD) clean
		