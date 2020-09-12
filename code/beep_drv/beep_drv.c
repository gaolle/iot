//��������ʹ�õ�ͷ�ļ���������linux�ں�Դ��
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

static dev_t beep_num;//�豸��
static unsigned int beep_major = 0;//���豸�š�����--��̬ע�ᣬ0---��̬���� 
static unsigned int beep_minor = 0;//���豸��

static void __iomem *GPD0CON;//����Ĵ����������ַ
static void __iomem *GPD0DAT;//����Ĵ����������ַ

static struct class * gec210_beep_class=NULL;
static struct device * gec210_beep_device = NULL;
static struct resource *beep_res;
//1.����һ��cdev-->����һ���ַ��豸����
static struct cdev gec210_beep_cdev;


//2.���岢��ʼ��һ���ļ�������
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

//Ӧ�ó���ʹ��write()����������д���ݣ������������У�ʹ��write()����������
//Ӧ�ó���д���������ݿ������ж��壺buf[0]---beep��״̬:1--on;0--off
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

//�����������ں���
static int __init gec210_beep_init(void)
{
	int ret;
	//3�������豸��
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
	
	//4.��ʼ��cdev
	cdev_init(&gec210_beep_cdev, &gec210_beep_fops);
	
	//5.��cdev����linux�ں�
	ret =  cdev_add(&gec210_beep_cdev, beep_num, 1);
	if(ret < 0){
		printk("cdev add error\n");
		goto cdev_add_err;
	}
		
	//6.����class
	gec210_beep_class = class_create(THIS_MODULE, "beep_class");
	if(gec210_beep_class == NULL){
		printk("class create error\n");
		ret = -EBUSY;
		goto class_create_error;
	}
	
	//7.����device
	gec210_beep_device = device_create(gec210_beep_class,NULL,beep_num, NULL, "beep_drv");
	if(gec210_beep_device == NULL)
	{
		printk("device create error\n");
		ret = -EBUSY;
		goto device_create_error;
	}
	
	//8.���������ڴ���
	beep_res = request_mem_region(0xE02000A0, 8,"GPD0_beep");
	if(beep_res == NULL)
	{
		printk("request mem error\n");
		ret = -EBUSY;
		goto request_mem_error;
	}
	
	//9.���붯̬�ڴ�
	GPD0CON = ioremap (0xE02000A0, 8);
	if(GPD0CON == NULL)
	{
		printk("ioeremap error\n");
		ret = -EBUSY;
		goto ioremap_error;
	}
	GPD0DAT = GPD0CON + 4;
	
	//10.ͨ�������ַ���ʼĴ���
	*(unsigned int *)GPD0CON &= ~0xf;
	*(unsigned int *)GPD0CON |= 0x1;  //GPD0_0�������ó��������
	
	*(unsigned int *)GPD0DAT &= ~(1<<0); //GPD0_0~3����ߵ�ƽ��beeps off
	
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


//��������ĳ��ں���
static void __exit gec210_beep_exit(void)
{
	
	//ע���豸��
	unregister_chrdev_region(beep_num, 1);
	//ɾ��һ��cdev
	cdev_del(&gec210_beep_cdev);
	
	//������device
	device_destroy(gec210_beep_class, beep_num);
	
	//�ټ�������
	class_destroy(gec210_beep_class);
	
	//�ͷ������ڴ���
	release_mem_region(0xE02000A0, 8);
	
	//���IO�ڴ�Ķ�̬ӳ��
	iounmap(GPD0CON);

	
	printk("gec210 beep driver exit\n");
}

//module����ںͳ���
module_init(gec210_beep_init); //�����������ڣ���װ���� #insmod beep_drv.ko��ʱ�����
module_exit(gec210_beep_exit); //��������ĳ��ڣ�ж������ #rmmod beep_drv��ʱ�����

//module�����������֤
MODULE_AUTHOR("2196481172@qq.com");
MODULE_DESCRIPTION("beep driver for GEC210");
MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
