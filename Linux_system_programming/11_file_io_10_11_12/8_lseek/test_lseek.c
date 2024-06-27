#include <stdio.h>
#include <fcntl.h>

int main()
{
	//int fd = open("hello.txt", O_RDWR);
	//int fd = open("hello.txt", O_WRONLY | O_APPEND);
	int fd = open("hello.txt", O_RDONLY);
	char buf[10];
	off_t curpos;
	if (fd < 0) {
		perror("open failed");
	} else {
		printf("Opening file successful\n");
		//we can seek zero bytes from the current position to determine the current offset
		curpos = lseek(fd, 0, SEEK_CUR);
		printf("curpos:%lu\n", curpos);
		read(fd, buf, sizeof(buf));
		perror("read operation");
		printf("Buffer:%s\n", buf);
		curpos = lseek(fd, 0, SEEK_CUR);
		printf("curpos:%lu\n", curpos);
		read(fd, buf, sizeof(buf));
		perror("read operation");
		printf("Buffer:%s\n", buf);
		curpos = lseek(fd, 0, SEEK_CUR);
		printf("curpos:%lu\n", curpos);
		close(fd);
	}
	return 0;
}
