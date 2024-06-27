#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/* The Single UNIX Specification includes XSI extensions that allow
 * applications to seek and perform I/O atomically.
 * #include <unistd.h>
 * ssize_t pread(int filedes, void *buf, size_t nbytes, off_t offset);
 * Return: number of bytes read, 0 if end of file, -1 on error
 * ssize_t pwrite(int fd, const void *buf, size_t nbytes, off_t offset);
 * Return: number of bytes written if OK, -1 on error.
 *
 * Calling pread() is equivalent to calling lseek() followed by a call
 * read(), with the following exceptions.
 * 1) There is no way to interrupt the two operations using pread().
 * 2) The file pointer is not updated."current file offset"
 * Calling pwrite() is equivalent to calling lseek() followed by a call
 * to write(), with similar exceptions
 */
int main(void)
{
	int fd;
	char buf[24] = {0};
	size_t n;

	if ((fd = open("yu", O_RDWR | O_CREAT, 0644)) < 0) {
		printf("preadaw: can't open or create yu: %s\n", strerror(errno));
		return 1;
	}
	
	n = strlen("tian xia you qing ren");
	printf("lseek:%d\n", lseek(fd, 0, SEEK_CUR));
	if (pwrite(fd, "tian xia you qing ren", n, 0) < 0) {
		printf("can't write to yu: %s\n", strerror(errno));
		return 1;
	}
	printf("after pwrite() lseek:%d\n", lseek(fd, 0, SEEK_CUR));
	
	printf("pread() lseek:%d\n", lseek(fd, 0, SEEK_CUR));
	if (pread(fd, buf, 24, 0) < 0) {
		printf("can't read from yu: %s\n", strerror(errno));
		return 1;
	}
	printf("%s\n", buf);
	printf("after pread() lseek:%d\n", lseek(fd, 0, SEEK_CUR));
	pwrite(fd, "hello", 5,0);

	if (read(fd, buf, 8) < 0) {
		printf("can't read from yu: %s\n", strerror(errno));
		return 1;
	}
	printf("after read(fd, buf, 8) lseek:%d\n",lseek(fd, 0, SEEK_CUR));
	buf[8] = '\0';
	printf("%s\n", buf);

	close(fd);
	return 0;
}
