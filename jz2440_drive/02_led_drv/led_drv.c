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

static struct class *leds_class;
static struct class_device *leds_class_devs[4];

volatile unsigned long *GPFCON = NULL;
volatile unsigned long *GPFDAT = NULL;

static int led_drv_open(struct inode *inode, struct file *file)
{
    printk("led_drv_open\n");

    //配置GPF4,5,6为输出引脚
    *GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
    *GPFCON |= (1<<8) | (1<<10) | (1<<12);

    return 0;
}

static ssize_t led_drv_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    int minor = MINOR(file->f_dentry->d_inode->i_rdev);
    int val;

    printk("led_drv_write\n");

    copy_from_user(&val, buf, count);

    switch(minor)
    {
        case 0:
        {
            if (val == 1)
            {
                // 所有灯亮
                *GPFDAT &= ~((1<<4) | (1<<5) | (1<<6));
                break;
            }
            else
            {
                // 所有灯灭
		        *GPFDAT |= (1<<4) | (1<<5) | (1<<6);
            }
        }

        case 1:
        {
            if (val == 1)
            {
                // 点亮1号灯
                *GPFDAT &= ~(1<<4);
                break;
            }
            else
            {
                // 熄灭1号灯
                *GPFDAT |= (1<<4);
                break;
            }
        }

        case 2:
        {
            if (val == 1)
            {
                // 点亮2号灯
                *GPFDAT &= ~(1<<5);
                break;
            }
            else
            {
                // 熄灭2号灯
                *GPFDAT |= (1<<5);
                break;
            }
        }

        case 3:
        {
            if (val == 1)
            {
                // 点亮3号灯
                *GPFDAT &= ~(1<<6);
                break;
            }
            else
            {
                // 熄灭3号灯
                *GPFDAT |= (1<<6);
                break;
            }
        }

    }

    return 0;
}

static struct file_operations led_drv_fops = {
    .owner = THIS_MODULE,
    .open  = led_drv_open,
    .write = led_drv_write,
};

int major;
int led_drv_init(void)
{
    int minor = 0;

    // 主设备号设为0表示自动分配主设备号
    major = register_chrdev(0, "led_drv", &led_drv_fops);    // 注册内核

    // 自动创建设备结点, 相当于mknod /dev/xxx c major 0
    leds_class = class_create(THIS_MODULE, "leds");

    leds_class_devs[0] = class_device_create(leds_class, NULL, MKDEV(major, 0), NULL, "leds");

    for(minor = 1; minor < 4; minor++)
    {
        leds_class_devs[minor] = class_device_create(leds_class, NULL, MKDEV(major, minor), NULL, "led%d", minor);
    }

    GPFCON = (volatile unsigned long *)ioremap(0x56000050, 16);
    GPFDAT = GPFCON + 1;

    return 0;
}

static void led_drv_exit(void)
{
    int minor;

    unregister_chrdev(major, "led_drv");    // 卸载

    for(minor = 0; minor < 4; minor++)
    {
        class_device_unregister(leds_class_devs[minor]);
    }
    
    class_destroy(leds_class);

    iounmap(GPFCON);
}

module_init(led_drv_init);
module_exit(led_drv_exit);

MODULE_LICENSE("GPL");
