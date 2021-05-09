// #include <linux/module.h>
// #include <linux/kernel.h>
// #include <linux/fs.h>
// #include <linux/init.h>
// #include <linux/delay.h>
// #include <asm/uaccess.h>
// #include <asm/irq.h>
// #include <asm/io.h>
// #include <asm/arch/regs-gpio.h>
// #include <asm/hardware.h>

// static struct class *button_class;
// static struct class_device *button_class_dev;

// volatile unsigned long *GPFCON = NULL;
// volatile unsigned long *GPFDAT = NULL;
// volatile unsigned long *GPFUP = NULL;

// volatile unsigned long *GPGCON = NULL;
// volatile unsigned long *GPGDAT = NULL;
// volatile unsigned long *GPGUP = NULL;

// static int button_drv_open(struct inode *inode, struct file *file)
// {
//     /* 配置GPF0, GPF2, GPG3为输入引脚 */
//     printk("button_drv_open\n");
//     // *GPFCON &= ~((3<<0) | (3<<4));
//     // *GPGCON &= ~((3<<6)); 

//     // /* 输入上拉 */
//     // *GPFUP &= ~((1<<0) | (1<<2));
//     // *GPGUP &= ~(1<<3);
// }

// ssize_t button_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
// {
//     /* 返回4个引脚的电平 */
// 	unsigned char key_vals[4];
// 	int regval;

// 	if (size != sizeof(key_vals))
// 		return -EINVAL;

// 	/* 读GPF0,2 */
// 	regval = *GPFDAT;
// 	key_vals[0] = (regval & (1<<0)) ? 1 : 0;
// 	key_vals[1] = (regval & (1<<2)) ? 1 : 0;
	

// 	/* 读GPG3,11 */
// 	regval = *GPGDAT;
// 	key_vals[2] = (regval & (1<<3)) ? 1 : 0;
// 	key_vals[3] = (regval & (1<<11)) ? 1 : 0;

// 	copy_to_user(buf, key_vals, sizeof(key_vals));
	
// 	return sizeof(key_vals);
// }

// static struct file_operations button_drv_fops = {
//     .owner = THIS_MODULE,
//     .open  = button_drv_open,
//     .read  = button_drv_read,
// };

// int major;
// int button_drv_init(void)
// {
//     major = register_chrdev(0, "button_drv", &button_drv_fops);

//     button_class = class_create(THIS_MODULE, "buttondrv");

//     button_class_dev = class_device_create(button_class, NULL, MKDEV(major, 0), NULL, "mybuttons");

//     // GPFCON = (volatile unsigned long *)ioremap(0x56000050, 20);
//     // GPFDAT = GPFCON + 1;
//     // GPFUP  = GPFCON + 2;

//     // GPGCON = (volatile unsigned long *)ioremap(0x56000060, 20);
//     // GPGDAT = GPFCON + 1;
//     // GPGUP  = GPFCON + 2;

//     return 0;
// }

// static void button_drv_exit(void)
// {
//     // unregister_chrdev(major, "button_drv");

//     // class_device_unregister(button_class_dev);
//     // class_destroy(button_class);

//     // iounmap(GPFCON);
//     // iounmap(GPGCON);
// }

// module_init(button_drv_init);
// module_exit(button_drv_exit);

// MODULE_LICENSE("GPL");

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

static struct class *mybuttons_class;
static struct class_device *mybuttons_class_devs;

volatile unsigned long *GPFCON = NULL;
volatile unsigned long *GPFDAT = NULL;
volatile unsigned long *GPFUP = NULL;

volatile unsigned long *GPGCON = NULL;
volatile unsigned long *GPGDAT = NULL;
volatile unsigned long *GPGUP = NULL;

static int button_drv_open(struct inode *inode, struct file *file)
{
    printk("button_drv_open\n");

    /* 配置GPF0, GPF2, GPG3为输入引脚 */
    *GPFCON &= ~((3<<0) | (3<<4));
    *GPGCON &= ~((3<<6)); 

    /* 输入上拉 */
    *GPFUP &= ~((1<<0) | (1<<2));
    *GPGUP &= ~(1<<3);

    return 0;
}

ssize_t button_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
    /* 返回4个引脚的电平 */
	unsigned char key_vals[4];
	int regval;

	if (size != sizeof(key_vals))
		return -EINVAL;

	/* 读GPF0,2 */
	regval = *GPFDAT;
	key_vals[0] = (regval & (1<<0)) ? 1 : 0;
	key_vals[1] = (regval & (1<<2)) ? 1 : 0;
	

	/* 读GPG3,11 */
	regval = *GPGDAT;
	key_vals[2] = (regval & (1<<3)) ? 1 : 0;
	key_vals[3] = (regval & (1<<11)) ? 1 : 0;

	copy_to_user(buf, key_vals, sizeof(key_vals));
	
	return sizeof(key_vals);
}

static struct file_operations button_drv_fops = {
    .owner = THIS_MODULE,
    .open  = button_drv_open,
    .read = button_drv_read,
};

int major;
int button_drv_init(void)
{
    int minor = 0;

    // 主设备号设为0表示自动分配主设备号
    major = register_chrdev(0, "button_drv", &button_drv_fops);    // 注册内核

    // 自动创建设备结点, 相当于mknod /dev/xxx c major 0
    mybuttons_class = class_create(THIS_MODULE, "mybuttons");

    mybuttons_class_devs = class_device_create(mybuttons_class, NULL, MKDEV(major, 0), NULL, "mybuttons");

    GPFCON = (volatile unsigned long *)ioremap(0x56000050, 100);
    GPFDAT = GPFCON + 1;
    GPFUP  = GPFCON + 2;

    //GPGCON = (volatile unsigned long *)ioremap(0x56000060, 20);
    GPGCON = GPFDAT + 4;
    GPGDAT = GPFCON + 5;
    GPGUP  = GPFCON + 6;

    return 0;
}

static void button_drv_exit(void)
{
    int minor;

    unregister_chrdev(major, "button_drv");    // 卸载
    class_device_unregister(mybuttons_class_devs);
    class_destroy(mybuttons_class);
    iounmap(GPFCON);
    iounmap(GPGCON);
}

module_init(button_drv_init);
module_exit(button_drv_exit);

MODULE_LICENSE("GPL");
