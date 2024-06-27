/*This program will create ____ child processes?*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	fork();
	fork();
	fork();
	printf("embedded\n");
	return 0;
}

/* this will print 8 times
each fork call doubles the process,
1st call: original process + fork() = 2 process
2nd call: 2 * above = 4 process
3rd call: 2 * above = 8 process
*/