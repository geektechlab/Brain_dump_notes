/*What is the output of this program?*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	//execl("/bin/ls",NULL);
	execl("/bin/ls","ls",NULL);
	return 0;
}
