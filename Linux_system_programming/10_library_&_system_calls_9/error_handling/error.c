#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd = open("hello.txt", O_RDWR);
	if (fd < 0) {
		printf("Open Failed\t error:%d\n", errno);
	} else {
		printf("Open Successful\n");
		close(fd);
	}
	return 0;
}

