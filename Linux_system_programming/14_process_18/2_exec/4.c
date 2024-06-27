#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	printf("Can you see me [ONE]\n");
	execl("./test","progname","arg1","arg2",NULL);	
	/* next line will not get executed because address space will get changed by exec call */
	/* above exec call will replace current process address space with test 's address space */
	/* whenever any program is executed, it is a process, so when ./4 will run, it becomes process */
	printf("Can you see me [TWO]\n");
	return 0;
}
