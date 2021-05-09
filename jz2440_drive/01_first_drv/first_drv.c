#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/regs-gpio.h>
#include <asm/hardware.h>

static struct class *firstdrv_class;
static struct class_device *firstdrv_class_dev;

static int first_drv_open(struct inode *inode, struct file *file)
{
    printk("first_drv_open\n");
    return 0;
}

static ssize_t first_drv_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk("first_drv_write\n");
    return 0;
}

static struct file_operations first_drv_fops = {
    .owner = THIS_MODULE,
    .open  = first_drv_open,
    .write = first_drv_write,
};

int major;
int first_drv_init(void)
{
    // 主设备号设为0表示自动分配主设备号
    major = register_chrdev(0, "first_drv", &first_drv_fops);    // 注册内核

    // 自动创建设备结点, 相当于mknod /dev/xxx c major 0
    firstdrv_class = class_create(THIS_MODULE, "firstdrv");
    firstdrv_class_dev = class_device_create(firstdrv_class, NULL, MKDEV(major, 0), NULL, "xxx");

    return 0;
}

static void first_drv_exit(void)
{
    unregister_chrdev(major, "first_drv");    // 卸载

    class_device_unregister(firstdrv_class_dev);
    class_destroy(firstdrv_class);
}

module_init(first_drv_init);
module_exit(first_drv_exit);

MODULE_LICENSE("GPL");
