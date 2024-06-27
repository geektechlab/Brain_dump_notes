#include <unistd.h>
#include <stdio.h>

int globval = 6;		/* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
	int autoval;		/* automatic variable on the stack */
	pid_t pid;

	autoval = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		printf("write %s to stdout error\n", buf);
	printf("before fork\n");	/* we don't flush stdout */

	if ((pid = fork()) < 0) {
		printf("fork error\n");
		return 1;
	}
	else if (pid == 0)	{	/* child */
		++globval;			/* modity variables */
		++autoval;
	}
	else					/* parent */
		sleep(2);

	printf("pid = %d, global = %d, autoval = %d\n", 
			getpid(), globval, autoval);
			/* above will get printed by 2 times. This is because of copy on write, parent will print same value but child will print incremented */
	return 0;
}
