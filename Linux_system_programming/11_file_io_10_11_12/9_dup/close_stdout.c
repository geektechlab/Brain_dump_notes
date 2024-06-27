#include <stdio.h>

int main()
{
	close(1);
	printf("Hello World");
	perror("printf");
	return 0;
}
