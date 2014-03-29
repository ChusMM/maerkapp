#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x6b2d22f7, "module_layout" },
	{ 0xfd6293c2, "boot_tvec_bases" },
	{ 0x722bbf1d, "platform_driver_unregister" },
	{ 0x529534b3, "class_destroy" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x50c85752, "platform_driver_register" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0xd25132bf, "__class_create" },
	{ 0x4074f48, "ioremap" },
	{ 0x43a53735, "__alloc_workqueue_key" },
	{ 0x81a2086f, "__register_chrdev" },
	{ 0x436c2179, "iowrite32" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x328a05f1, "strncpy" },
	{ 0xbc5a01fb, "platform_get_resource" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x4c905451, "_dev_info" },
	{ 0xd471b6d6, "of_irq_to_resource" },
	{ 0x3a2496e1, "dev_err" },
	{ 0x67e7dd59, "of_address_to_resource" },
	{ 0x47c6b372, "of_match_device" },
	{ 0x528c709d, "simple_read_from_buffer" },
	{ 0x461ebfa0, "__copy_tofrom_user" },
	{ 0x25bced23, "call_usermodehelper_fns" },
	{ 0xb81960ca, "snprintf" },
	{ 0xe484e35f, "ioread32" },
	{ 0x38bd731f, "queue_delayed_work" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cxlnx,int-generator-1.01.a*");
