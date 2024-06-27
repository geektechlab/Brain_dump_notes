#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret;

	//vi is passed as the first argument so a program can examine its first argument argv[0] to discover the 
	//name of its binary image
	ret = execl("/usr/bin/vi", "vi", NULL);
	if (ret == -1)
		perror("execl");

}
