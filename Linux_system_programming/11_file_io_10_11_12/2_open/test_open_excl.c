#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("hello.txt", O_WRONLY|O_CREAT|O_EXCL, 0666);
	if (fd < 0) {
		perror("open failed");
	} else {
		printf("Opening file successful\n");
		close(fd);
	}
	return 0;
}
