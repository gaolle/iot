//Çý¶¯³ÌÐòÊ¹ÓÃµÄÍ·ÎÄŒþ£¬ÀŽ×ÔÓÚlinuxÄÚºËÔŽÂë
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/fs.h>

#define GEC210_LED_ON	_IOW('L',1,unsigned int) 
#define GEC210_LED_OFF	_IOW('L',2,unsigned int)

static dev_t led_num;//Éè±žºÅ
static unsigned int led_major = 0;//Ö÷Éè±žºÅ¡£·ÇÁã--Ÿ²Ì¬×¢²á£¬0---¶¯Ì¬·ÖÅä 
static unsigned int led_minor = 0;//ŽÎÉè±žºÅ

static void __iomem *GPJ2CON;//¶šÒåŒÄŽæÆ÷µÄÐéÄâµØÖ·
static void __iomem *GPJ2DAT;//¶šÒåŒÄŽæÆ÷µÄÐéÄâµØÖ·

static struct class * gec210_led_class=NULL;
static struct device * gec210_led_device = NULL;
static struct resource *led_res;
//1.¶šÒåÒ»žöcdev-->¶šÒåÒ»žö×Ö·ûÉè±žÇý¶¯
static struct cdev gec210_led_cdev;


//2.¶šÒå²¢³õÊŒ»¯Ò»žöÎÄŒþ²Ù×÷Œ¯
static int gec210_led_open(struct inode *inode, struct file *filp)
{
	printk("gec210 led openning\n");
	return 0;
}

static int gec210_led_release(struct inode *inode, struct file *filp)
{
	printk("gec210 led closing\n");
	return 0;
}

//ÓŠÓÃ³ÌÐòÊ¹ÓÃwrite()ÏòÇý¶¯³ÌÐòÐŽÊýŸÝ£¬ÔÚÇý¶¯³ÌÐòÖÐ£¬Ê¹ÓÃwrite()ÀŽœÓÊÕÊýŸÝ
//ÓŠÓÃ³ÌÐòÐŽÏÂÀŽµÄÊýŸÝ¿ÉÒÔ×ÔÐÐ¶šÒå£ºchar buf[2], buf[1]---ÄÄÒ»ÕµµÆ£»buf[0]---ledµÄ×ŽÌ¬
ssize_t gec210_led_ioctl(struct file *filp, unsigned int cmd, unsigned long args)
{
	
	if((args > 4) || (args < 0))
		return -EINVAL;
	switch(cmd){
		
	case GEC210_LED_ON:
		*(unsigned int *)GPJ2DAT &= ~(1<<(args-1));
		break;
		
	case GEC210_LED_OFF:
		*(unsigned int *)GPJ2DAT |= (1<<(args-1));
		break;
		
	default:
		return -ENOIOCTLCMD;
	}
	
	return 0;//正确返回
}

static struct file_operations gec210_led_fops = {
	.owner = THIS_MODULE,
	.open = gec210_led_open,
	.unlocked_ioctl = gec210_led_ioctl,
	.release = gec210_led_release,
};

//Çý¶¯³ÌÐòµÄÈë¿Úº¯Êý
static int __init gec210_led_init(void)
{
	int ret;
	//3¡¢ÉêÇëÉè±žºÅ
	if(led_major == 0)
		ret = alloc_chrdev_region(&led_num, led_minor,1, "led_device");
	else{
		led_num = MKDEV(led_major,led_minor);
		ret = register_chrdev_region(led_num, 1, "led_device");
	}
	if(ret < 0){
		printk("can not get led num\n");
		return ret;
	}
	
	//4.³õÊŒ»¯cdev
	cdev_init(&gec210_led_cdev, &gec210_led_fops);
	
	//5.œ«cdevŒÓÈëlinuxÄÚºË
	ret =  cdev_add(&gec210_led_cdev, led_num, 1);
	if(ret < 0){
		printk("cdev add error\n");
		goto cdev_add_err;
	}
		
	//6.ŽŽœšclass
	gec210_led_class = class_create(THIS_MODULE, "led_class");
	if(gec210_led_class == NULL){
		printk("class create error\n");
		ret = -EBUSY;
		goto class_create_error;
	}
	
	//7.ŽŽœšdevice
	gec210_led_device = device_create(gec210_led_class,NULL,led_num, NULL, "led_drv");
	if(gec210_led_device == NULL)
	{
		printk("device create error\n");
		ret = -EBUSY;
		goto device_create_error;
	}
	
	//8.ÉêÇëÎïÀíÄÚŽæÇø
	led_res = request_mem_region(0xE0200280, 8,"GPJ2_LED");
	if(led_res == NULL)
	{
		printk("request mem error\n");
		ret = -EBUSY;
		goto request_mem_error;
	}
	
	//9.ÉêÇë¶¯Ì¬ÄÚŽæ
	GPJ2CON = ioremap (0xE0200280, 8);
	if(GPJ2CON == NULL)
	{
		printk("ioeremap error\n");
		ret = -EBUSY;
		goto ioremap_error;
	}
	GPJ2DAT = GPJ2CON + 4;
	
	//10.Íš¹ýÐéÄâµØÖ··ÃÎÊŒÄŽæÆ÷
	*(unsigned int *)GPJ2CON &= ~0xffff;
	*(unsigned int *)GPJ2CON |= 0x1111;  //GPJ2_0~3ËÄžöÒýœÅÅäÖÃ³ÉÊä³öÒýœÅ
	
	*(unsigned int *)GPJ2DAT |=0xf; //GPJ2_0~3Êä³öžßµçÆœ£¬LEDs off
	
	printk("gec210 led driver init \n"); //printf()
	
	return 0;
	
	
ioremap_error:	
	release_mem_region(0xE0200280, 8);
request_mem_error:	
	class_destroy(gec210_led_class);
device_create_error:	
	class_destroy(gec210_led_class);
class_create_error:
	cdev_del(&gec210_led_cdev);
cdev_add_err:
	unregister_chrdev_region(led_num, 1);
	
	return ret;
}


//Çý¶¯³ÌÐòµÄ³ö¿Úº¯Êý
static void __exit gec210_led_exit(void)
{
	
	//×¢ÏúÉè±žºÅ
	unregister_chrdev_region(led_num, 1);
	//ÉŸ³ýÒ»žöcdev
	cdev_del(&gec210_led_cdev);
	
	//ÏÈÏú»Ùdevice
	device_destroy(gec210_led_class, led_num);
	
	//ÔÙŒÌÐøÏú»Ù
	class_destroy(gec210_led_class);
	
	//ÊÍ·ÅÎïÀíÄÚŽæÇø
	release_mem_region(0xE0200280, 8);
	
	//œâ³ýIOÄÚŽæµÄ¶¯Ì¬Ó³Éä
	iounmap(GPJ2CON);
	
	
	
	
	
	printk("gec210 led driver exit\n");
}

//moduleµÄÈë¿ÚºÍ³ö¿Ú
module_init(gec210_led_init); //Çý¶¯³ÌÐòµÄÈë¿Ú£¬°²×°Çý¶¯ #insmod led_drv.koµÄÊ±ºòµ÷ÓÃ
module_exit(gec210_led_exit); //Çý¶¯³ÌÐòµÄ³ö¿Ú£¬Ð¶ÔØÇý¶¯ #rmmod led_drvµÄÊ±ºòµ÷ÓÃ


//moduleµÄÃèÊöºÍÐí¿ÉÖ€
MODULE_AUTHOR("2196481172@qq.com");
MODULE_DESCRIPTION("led driver for GEC210");
MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
