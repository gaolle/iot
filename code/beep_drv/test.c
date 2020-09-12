#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define GEC210_BEEP_ON	_IO('B',1)
#define GEC210_BEEP_OFF	_IO('B',2)

int main(void)
{
	int fd;
	int ret;
	fd = open("/dev/beep_drv", O_RDWR);
	if(fd == -1)
	{
		perror("open beep_drv");
		return -1;
	}
	while(1)
	{
		ret = ioctl(fd, GEC210_BEEP_ON, 1);//LED1 on
		if(ret == -1)
		{
			perror("IOCTL");
			return -1;
		}
		sleep(1);
		ret = ioctl(fd, GEC210_BEEP_OFF, 1);//LED1 off
		if(ret == -1)
		{
			perror("IOCTL");
			return -1;
		}
		sleep(1);
	}
	
	close(fd);
	
	return 0;	
}
