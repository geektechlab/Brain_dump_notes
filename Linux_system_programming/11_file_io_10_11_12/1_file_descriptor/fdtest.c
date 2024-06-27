#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[256];
	int length;
	//write(STDOUT_FILENO, "Hello STDOUT\n", sizeof("Hello STDOUT\n"));
	//write(STDERR_FILENO, "Hello STDERR\n", sizeof("Hello STDERR\n"));
	length = read(STDIN_FILENO, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Data Read from console:%s\n", buffer);
	return 0;
}
