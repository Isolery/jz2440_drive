#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int fd;

void my_signal_fun(int signum)
{
	unsigned char key_val;
	read(fd, &key_val, 1);
	printf("key_val: 0x%x\n", key_val);
}

int main(int argc, char **argv)
{
	int ret;
	int oflags;

	signal(SIGIO, my_signal_fun);

	fd = open("/dev/mybuttons", O_RDWR);
	if(fd < 0)
		printf("can't open!\n");
	else
		printf("open ok!\n");

	fcntl(fd, F_SETOWN, getpid());    // 将应用程序的PID告诉驱动程序

	oflags = fcntl(fd, F_GETFL);

	fcntl(fd, F_SETFL, oflags | FASYNC);   // 改变fasync标记, 最终会调用驱动的fasync -> fasync_helper -> 初始化buttons_async结构体

	while(1)
	{
		sleep(1000);
	}
	
	return 0;
}
