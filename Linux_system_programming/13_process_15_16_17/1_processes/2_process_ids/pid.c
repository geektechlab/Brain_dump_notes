#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("process ID: %d\n", getpid());
	printf("parent process ID: %d\n", getppid());
	printf("real user ID: %d\n", getuid());
	printf("effective user ID: %d\n", geteuid());
	printf("real group ID: %d\n", getgid());
	printf("effective group ID: %d\n", getegid());

	return 0;
}
