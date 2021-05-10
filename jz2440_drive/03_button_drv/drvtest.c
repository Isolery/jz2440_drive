#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	unsigned char key_val;
	int ret;

	fd = open("/dev/mybuttons", O_RDWR);                 // 阻塞方式打开
	//fd = open("/dev/mybuttons", O_RDWR | O_NONBLOCK);    // 非阻塞方式打开

	if(fd < 0)
		printf("can't open!\n");
	else
		printf("open ok!\n");

	while(1)
	{
		ret = read(fd, &key_val, 1);
		printf("key_val : 0x%x ret = %d\n", key_val, ret);
		//sleep(5);
	}
	
	return 0;
}
