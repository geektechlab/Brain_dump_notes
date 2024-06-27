#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

#define CHILD 0

main(){
	int fd = 10;
	char buf[2];
	pid_t pid;	
	int childstatus;
	pid = fork();
	if( pid == CHILD){
		sleep(4);
		read(fd,buf,2);
		/* Though copy on write, this will be error because changes in open file will be copied to other befor fork, but here file is opened after fork(), so it will not be reflected in child and cause error. */
		perror("child:");
		printf(" in child %c\n",buf[0]);
		printf(" in child %c\n",buf[1]);
		close(fd);
	}
	// parent
	else{
		fd = open("./test",O_RDONLY);
		printf("parent waiting for child\n");
		wait(&childstatus);
		read(fd,buf,2);
		printf(" in parent %c\n",buf[0]);
		printf(" in parent %c\n",buf[1]);
		close(fd);
	}
}

