/*A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.

All orphan process will get assigned to systemd ( /lib/systemd/systemd --user ). We can have two init managers, systemd and sysvinit. In case of systemd, parent pid of systemd will be assigned. In case of sysvinit, 1 will be assigned to parent pid of the orphan process.
*/

#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    // Create a child process       
    int pid = fork(); 
  
    if (pid > 0) 
        printf("in parent process:%u\n", getpid()); 
  
    // Note that pid is 0 in child process 
    // and negative if fork() fails 
    else if (pid == 0) 
    { 
        sleep(30); 
        printf("in child process"); 
    } 
  
    return 0; 
} 
