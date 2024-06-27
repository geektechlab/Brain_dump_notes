#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

static int func(int arg)
{
	int j;

	printf("Program break in child:  %10p\n", sbrk(0));
	for (j = 0; j < 0x100; j++)
		if (malloc(0x800) == NULL) {
			perror("malloc");
			exit(1);
		}
	printf("Program break in child:  %10p\n", sbrk(0));

	return arg;
}

/* _sbrk increments program's data space by icrement bytes and gives program break ( start of bytes ). _sbrk(0) gives current location of program break. _brk() sets end of data segment ( program break ) directly and ensures doesn't exceed limit. */

int main(void)
{
	pid_t CPid;
	int status, arg=0;

	printf("Program break in parent: %10p\n", sbrk(0));

	switch (fork()) {

	case -1:
		perror("fork");
		exit(1);

	case 0:
		/* Child calls func() and uses return value as exit 
		   status */
		exit(func(arg));

	default:

		/* Parent waits for child to terminate. It can determine the
		   result of func() by inspecting 'status' */

		if (wait(&status) == -1) {
			perror("wait");
			exit(1);
		}

		printf("Program break in parent: %10p\n", sbrk(0));
		/* Copy on write: since _sbrk is called again child, it will not affect _sbrk(0) in parent */
	}
	return 0;
}
