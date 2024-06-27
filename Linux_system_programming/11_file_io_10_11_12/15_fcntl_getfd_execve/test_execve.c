# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

main(){
	//fcntl(0,F_SETFD,FD_CLOEXEC) ; //set close on exec flag
	//fcntl(1,F_SETFD,FD_CLOEXEC) ; 
	//fcntl(2,F_SETFD,FD_CLOEXEC) ; 
	execve("./test",NULL, NULL);	
	printf("Can you see me [TWO]\n");
}
