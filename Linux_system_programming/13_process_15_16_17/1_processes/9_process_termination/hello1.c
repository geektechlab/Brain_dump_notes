#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int func()
{
	//return 0;
	exit(0);
}

int main(int argc, const char *argv[])
{
	printf("%s\n", "hello world");
	func();
	printf("printing\n");
	//return 0; 
	exit(0);

}
