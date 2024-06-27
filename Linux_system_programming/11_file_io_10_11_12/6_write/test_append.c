#include <stdio.h>
#include <fcntl.h>

int main()
{
	char buf[100];
	ssize_t write_retval;
	int fd = open("hello.txt", O_WRONLY|O_APPEND);
	if (fd < 0) {
		perror("open failed");
	} else {
		printf("Opening file successful\n");
		printf("Enter the Data to be written into hello.txt:");
		scanf("%[^\n]s", buf);
		write_retval = write(fd, buf, strlen(buf));
		printf("write_retval:%d\t strlen(buf):%d\n", write_retval, strlen(buf));
		close(fd);
	}
	return 0;
}
