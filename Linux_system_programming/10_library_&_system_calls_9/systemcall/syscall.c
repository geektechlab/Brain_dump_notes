#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(){
   char str[]={"Welcome to System Programming\n"};
//   int rv = syscall(SYS_write, 1, str, sizeof str); 
   int rv = syscall(1, 1, str, sizeof str); 
   return rv;
}

