#include <stdio.h>
#include <fcntl.h>

int main()
{
	ssize_t retval;
	char buffer[256];
	int fd = open("hello.txt", O_RDONLY);
	if (fd < 0) {
		perror("open failed");
	} else {
		printf("Opening file successful\n");
		do {
			memset(buffer, 0, sizeof(buffer));
			retval = read(fd, buffer, sizeof(buffer));
			printf("Buffer:%s read bytes:%d\n", buffer, retval);
			sleep(2);
		}while(retval != 0);
		close(fd);
	}
	return 0;
}
