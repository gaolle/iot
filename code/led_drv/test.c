#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define GEC210_LED_ON	_IOW('L',1,unsigned int) 
#define GEC210_LED_OFF	_IOW('L',2,unsigned int) 

int main(void)
{
	int fd;
	
	int ret;
	fd = open("/dev/led_drv", O_RDWR);
	if(fd == -1)
	{
		perror("open led_drv");
		return -1;
	}
	while(1)
	{
		int i;
		for(i=1;i<5;i++)
		{
				ret = ioctl(fd, GEC210_LED_ON, i);//LED1 on
					if(ret == -1)
					{
						perror("IOCTL");
						return -1;
					}
					sleep(1);
					ret = ioctl(fd, GEC210_LED_OFF, i);//LED1 off
					if(ret == -1)
					{
						perror("IOCTL");
						return -1;
					}
					sleep(1);
			
		}
	}

	close(fd);
	
	return 0;	
}
