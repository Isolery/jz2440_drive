#include <linux/module.h>
#include <linux/version.h>

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/pm.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/irq.h>
#include <asm/uaccess.h>
#include <asm/io.h>

static int major;
static struct class *led_class;
static struct class_device *led_class_devs;

static volatile unsigned long *gpio_con;
static volatile unsigned long *gpio_dat;
static int pin;

static led_open(struct inode *inode, struct file *file)
{
    //配置GPF4,5,6为输出引脚
    *gpio_con &= ~(3<<(pin*2));
    *gpio_con |= (1<<(pin*2));

    return 0;
}

static ssize_t led_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    int val;

    copy_from_user(&val, buf, count);

    if (val == 1)
    {
        // 灯亮
        *gpio_dat &= ~(1<<pin);
    }
    else
    {
        // 灯灭
        *gpio_dat |= (1<<pin);
    }
 
    return 0;
}

static struct file_operations led_fops = {
    .owner = THIS_MODULE,
    .open  = led_open,
    .write = led_write,
};

static int led_probe(struct platform_device *pdev)
{
    struct resource *res;

    // 根据platform_device的资源进行ioremap
    res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

    gpio_con = ioremap(res->start, res->end - res->start + 1);
    gpio_dat = gpio_con + 1;

    res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
    pin = res->start;

    // 注册字符设备驱动程序
    printk("led_probe, found led\n");

    major = register_chrdev(0, "myled", &led_fops);
    led_class = class_create(THIS_MODULE, "myled");
    led_class_devs = class_device_create(led_class, NULL, MKDEV(major, 0), NULL, "led");    // /dev/led

    return 0;
}

static int led_remove(struct platform_device *pdev)
{
    // 卸载字符设备驱动程序
    unregister_chrdev(major, "myled"); 
    class_device_unregister(led_class_devs);
    class_destroy(led_class);

    // iounmap
    iounmap(gpio_con);

    printk("led_remove, remove led\n");

    return 0;
}

struct platform_driver led_drv = {
    .probe   = led_probe,
    .remove  = led_remove,
    .driver  = {
        .name = "myled",
    }
};

static int led_drv_init(void)
{
    platform_driver_register(&led_drv);
}

static void led_drv_exit(void)
{
    platform_driver_unregister(&led_drv);
}

module_init(led_drv_init);
module_exit(led_drv_exit);

MODULE_LICENSE("GPL");
