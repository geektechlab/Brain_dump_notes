#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd = open("hello.txt", O_RDWR);
	if (fd < 0) {
		perror("Open Failed");
	} else {
		printf("Open Successful\n");
		close(fd);
	}
	return 0;
}

