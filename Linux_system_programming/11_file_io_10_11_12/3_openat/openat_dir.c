#include <stdio.h>
#include <fcntl.h>

int main()
{	
	int fd, dirfd ;
	if (!chdir("/tmp")) {
		printf("Changed to tmp directory\n");
	} else {
		perror("Failed to change to tmp directory");
	}
	
	dirfd = open("/home/panther2/Linux_System_Prog",  O_DIRECTORY | O_RDONLY);
	perror("open");
	fd = openat(dirfd, "hello1.txt", O_RDONLY | O_CREAT, 0666);
	if (fd < 0) {
		perror("Openat failed");
	} else {
		printf("Openat successful\n");
		close(fd);
	}
	return 0;
}
