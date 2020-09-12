//驱动程序使用的头文件，来自于linux内核源码
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/ioctl.h>

#define GEC210_BEEP_ON	_IO('B',1)
#define GEC210_BEEP_OFF	_IO('B',2)

static dev_t beep_num;//设备号
static unsigned int beep_major = 0;//主设备号。非零--静态注册，0---动态分配 
static unsigned int beep_minor = 0;//次设备号

static void __iomem *GPD0CON;//定义寄存器的虚拟地址
static void __iomem *GPD0DAT;//定义寄存器的虚拟地址

static struct class * gec210_beep_class=NULL;
static struct device * gec210_beep_device = NULL;
static struct resource *beep_res;
//1.定义一个cdev-->定义一个字符设备驱动
static struct cdev gec210_beep_cdev;


//2.定义并初始化一个文件操作集
static int gec210_beep_open(struct inode *inode, struct file *filp)
{
	printk("gec210 beep openning\n");
	return 0;
}

static int gec210_beep_release(struct inode *inode, struct file *filp)
{
	*(unsigned int *)GPD0DAT &= ~(1<<0);
	printk("gec210 beep closing\n");
	return 0;
}

//应用程序使用write()向驱动程序写数据，在驱动程序中，使用write()来接收数据
//应用程序写下来的数据可以自行定义：buf[0]---beep的状态:1--on;0--off
ssize_t gec210_beep_ioctl(struct file *filp, unsigned int cmd, unsigned long args)
{
	
	switch(cmd){
		
	case GEC210_BEEP_ON:
		*(unsigned int *)GPD0DAT |= (1<<0);
		break;
		
	case GEC210_BEEP_OFF:
		*(unsigned int *)GPD0DAT &= ~(1<<0);
		break;
		
	default:
		return -ENOIOCTLCMD;
	}
}

static struct file_operations gec210_beep_fops = {
	.owner = THIS_MODULE,
	.open = gec210_beep_open,
	.unlocked_ioctl = gec210_beep_ioctl,
	.release = gec210_beep_release,
};

//驱动程序的入口函数
static int __init gec210_beep_init(void)
{
	int ret;
	//3、申请设备号
	if(beep_major == 0)
		ret = alloc_chrdev_region(&beep_num, beep_minor,1, "beep_device");
	else{
		beep_num = MKDEV(beep_major,beep_minor);
		ret = register_chrdev_region(beep_num, 1, "beep_device");
	}
	if(ret < 0){
		printk("can not get beep num\n");
		return ret;
	}
	
	//4.初始化cdev
	cdev_init(&gec210_beep_cdev, &gec210_beep_fops);
	
	//5.将cdev加入linux内核
	ret =  cdev_add(&gec210_beep_cdev, beep_num, 1);
	if(ret < 0){
		printk("cdev add error\n");
		goto cdev_add_err;
	}
		
	//6.创建class
	gec210_beep_class = class_create(THIS_MODULE, "beep_class");
	if(gec210_beep_class == NULL){
		printk("class create error\n");
		ret = -EBUSY;
		goto class_create_error;
	}
	
	//7.创建device
	gec210_beep_device = device_create(gec210_beep_class,NULL,beep_num, NULL, "beep_drv");
	if(gec210_beep_device == NULL)
	{
		printk("device create error\n");
		ret = -EBUSY;
		goto device_create_error;
	}
	
	//8.申请物理内存区
	beep_res = request_mem_region(0xE02000A0, 8,"GPD0_beep");
	if(beep_res == NULL)
	{
		printk("request mem error\n");
		ret = -EBUSY;
		goto request_mem_error;
	}
	
	//9.申请动态内存
	GPD0CON = ioremap (0xE02000A0, 8);
	if(GPD0CON == NULL)
	{
		printk("ioeremap error\n");
		ret = -EBUSY;
		goto ioremap_error;
	}
	GPD0DAT = GPD0CON + 4;
	
	//10.通过虚拟地址访问寄存器
	*(unsigned int *)GPD0CON &= ~0xf;
	*(unsigned int *)GPD0CON |= 0x1;  //GPD0_0引脚配置成输出引脚
	
	*(unsigned int *)GPD0DAT &= ~(1<<0); //GPD0_0~3输出高电平，beeps off
	
	printk("gec210 beep driver init \n"); //printf()
	
	return 0;
	
	
ioremap_error:	
	release_mem_region(0xE02000A0, 8);
request_mem_error:	
	class_destroy(gec210_beep_class);
device_create_error:	
	class_destroy(gec210_beep_class);
class_create_error:
	cdev_del(&gec210_beep_cdev);
cdev_add_err:
	unregister_chrdev_region(beep_num, 1);
	
	return ret;
}


//驱动程序的出口函数
static void __exit gec210_beep_exit(void)
{
	
	//注销设备号
	unregister_chrdev_region(beep_num, 1);
	//删除一个cdev
	cdev_del(&gec210_beep_cdev);
	
	//先销毁device
	device_destroy(gec210_beep_class, beep_num);
	
	//再继续销毁
	class_destroy(gec210_beep_class);
	
	//释放物理内存区
	release_mem_region(0xE02000A0, 8);
	
	//解除IO内存的动态映射
	iounmap(GPD0CON);

	
	printk("gec210 beep driver exit\n");
}

//module的入口和出口
module_init(gec210_beep_init); //驱动程序的入口，安装驱动 #insmod beep_drv.ko的时候调用
module_exit(gec210_beep_exit); //驱动程序的出口，卸载驱动 #rmmod beep_drv的时候调用

//module的描述和许可证
MODULE_AUTHOR("2196481172@qq.com");
MODULE_DESCRIPTION("beep driver for GEC210");
MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
