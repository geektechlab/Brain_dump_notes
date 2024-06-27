/*
	A 'fork bomb' is when you attempt to create an infinite number of processes. 

*/

#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
int main() 
{
	while(1)
	{
		fork();
		perror("fork()");
	}

		return 0;

}

/* At each fork call process number gets doubled so if fork is called in loop, then 2^iterator processes will get created. Number of processes are limited by ulimit -a ? */
