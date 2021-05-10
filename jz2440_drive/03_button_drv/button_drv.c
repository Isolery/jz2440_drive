#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/regs-gpio.h>
#include <asm/hardware.h>
#include <linux/poll.h>

static struct class *mybuttons_class;
static struct class_device *mybuttons_class_devs;

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);

static DECLARE_MUTEX(button_lock);    // 定义互斥量(该宏已对信号量进行初始化)

/* 中断事件标志, 中断服务程序将它置1，button_drv_read将它清0 */
static volatile int ev_press = 0;

static struct fasync_struct *buttons_async;

struct pin_desc{
    unsigned int pin;
    unsigned int key_val;
};

/* 键值: 按下时, 0x01, 0x02, 0x03, 0x04 */
/* 键值: 松开时, 0x81, 0x82, 0x83, 0x84 */
static unsigned char key_val;

struct pin_desc pins_desc[4] = {
    {S3C2410_GPF0,  0x01}, 
    {S3C2410_GPF2,  0x02}, 
    {S3C2410_GPG3,  0x03}, 
    {S3C2410_GPG11, 0x04}, 
};

static irqreturn_t buttons_irq(int irq, void *dev_id)
{
    struct pin_desc *pindesc = (struct pin_desc *)dev_id;
    unsigned int pinval;

    pinval = s3c2410_gpio_getpin(pindesc->pin);

    if(pinval)
    {
        // 松开
        key_val = 0x80 | pindesc->key_val;
    }
    else
    {
        // 按下
        key_val = pindesc->key_val;
    }

    ev_press = 1;                           /* 表示中断发生了 */
    wake_up_interruptible(&button_waitq);   /* 唤醒休眠的进程 */

    kill_fasync(&buttons_async, SIGIO, POLL_IN);

    return IRQ_RETVAL(IRQ_HANDLED);
}

static int button_drv_open(struct inode *inode, struct file *file)
{
    printk("button_drv_open\n");

    down(&button_lock);   // 获取信号量

    request_irq(IRQ_EINT0,  buttons_irq, IRQT_BOTHEDGE, "S2", &pins_desc[0]);
    request_irq(IRQ_EINT2,  buttons_irq, IRQT_BOTHEDGE, "S3", &pins_desc[1]);
    request_irq(IRQ_EINT11, buttons_irq, IRQT_BOTHEDGE, "S4", &pins_desc[2]);
    request_irq(IRQ_EINT19, buttons_irq, IRQT_BOTHEDGE, "S5", &pins_desc[3]);

    return 0;
}

ssize_t button_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
    if (size != 1)
        return -EINVAL;

    /* 如果没有按键动作, 休眠 */
	wait_event_interruptible(button_waitq, ev_press);

    /* 如果有按键动作, 返回键值 */
	copy_to_user(buf, &key_val, 1);
	ev_press = 0;

	return 1;
}

int button_drv_release(struct inode *inode, struct file *file)
{
    free_irq(IRQ_EINT0,  &pins_desc[0]);
    free_irq(IRQ_EINT2,  &pins_desc[0]);
    free_irq(IRQ_EINT11, &pins_desc[0]);
    free_irq(IRQ_EINT19, &pins_desc[0]);

    up(&button_lock);

    return 0;
}

static unsigned button_drv_poll(struct file *file, poll_table *wait)
{
    unsigned int mask = 0;

    poll_wait(file, &button_waitq, wait);

    if(ev_press)
        mask |= POLLIN | POLLRDNORM;

    return mask;
}

static int button_drv_fasync(int fd, struct file *filp, int on)
{
    printk("driver: buttons_drv_fasync\n");
    return fasync_helper(fd, filp, on, &buttons_async);
}

static struct file_operations button_drv_fops = {
    .owner   =  THIS_MODULE,
    .open    =  button_drv_open,
    .read    =  button_drv_read,
    .release =  button_drv_release,
    .poll    =  button_drv_poll,
    .fasync  =  button_drv_fasync,
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
    
    return 0;
}

static void button_drv_exit(void)
{
    int minor;

    unregister_chrdev(major, "button_drv");    // 卸载
    class_device_unregister(mybuttons_class_devs);
    class_destroy(mybuttons_class);
}

module_init(button_drv_init);
module_exit(button_drv_exit);

MODULE_LICENSE("GPL");
