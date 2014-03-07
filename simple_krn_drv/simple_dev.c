
/*
 *    Description:
 *    	Sample Character driver to say hello & good bye though ioctls
 *    Author: Babu Neelam
 *
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/proc_fs.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <asm/uaccess.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <linux/string.h>
#include <asm/checksum.h>
#include <linux/err.h>
#include <linux/stat.h>
#include <linux/moduleparam.h>
#include "../simple_lib_include/simple_inc.h"

static int simple_dev_major;

static int
simple_dev_fops_open(struct inode *inode, struct file *filp)
{
	return (0);
}

static int
simple_dev_fops_close(struct inode *inode, struct file *filp)
{
	return (0);
}

static long
simple_dev_fops_ioctl(struct file *filp,
	unsigned int cmd, unsigned long arg)
{
	simple_ioc_t ioc;

	if (copy_from_user(&ioc, (void *)arg, sizeof (simple_ioc_t)))
            return (-EFAULT);

	switch (cmd) {

		case SIMPLE_DEV_IOC_SAY_HELLO:
			printk(KERN_INFO "gcov dev says hello \r\n");
			break;

		case SIMPLE_DEV_IOC_SAY_GOODBYE:
			printk(KERN_INFO "gcov dev says good bye\r\n");
			break;

		default :
			printk(KERN_CRIT "Invalid ioctl cmd %d\n", cmd);
			ioc.RetVal = -EINVAL;
			break;
	}

	if (copy_to_user((void *)arg, &ioc, sizeof (simple_ioc_t)))
            return (-EFAULT);

	return (ioc.RetVal);
}



static struct file_operations simple_dev_fops = {
	open	:	simple_dev_fops_open,
	release :	simple_dev_fops_close,
	unlocked_ioctl	:	simple_dev_fops_ioctl,
};


static int __init
simple_dev_init(void)
{
	simple_dev_major = register_chrdev(0, "simple_dev", &simple_dev_fops);
	if (simple_dev_major < 0) {
		printk(KERN_CRIT "Failed to register gcov device. Bailing out \n");
		return (-1);
	}

	printk(KERN_INFO "gcov dev module init complete \r\n");

	return ((simple_dev_major >= 0) ? 0 : simple_dev_major);
}

static void __exit
simple_dev_exit(void)
{
	unregister_chrdev(simple_dev_major, "simple_dev");
	printk(KERN_INFO "gcov dev module de-init complete \r\n");
}

module_init(simple_dev_init);
module_exit(simple_dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Babu Neelam");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Sample char driver");
