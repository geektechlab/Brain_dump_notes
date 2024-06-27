#include <stdio.h>
#include <fcntl.h>

/*The file’s offset can be greater than the file’s current size, in which case the next
write to the file will extend the file
This is referred to as creating a hole in a file and is
allowed. Any bytes in a file that have not been written are read back as 0.
*/

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{

	int fd;
	if ((fd = creat("file.nohole", 0666)) < 0)
		perror("creat error");

	if (write(fd, buf1, 10) != 10)
		perror("buf1 write error");

	/* offset now = 10 */

	if (write(fd, buf2, 10) != 10)
		perror("buf2 write error");
	/* offset now = 16394 */
	exit(0);

	
	return 0;
}
