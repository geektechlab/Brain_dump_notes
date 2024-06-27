/*
	We know that in C, local variables are located on the stack. 
	So if we print the address of a local variable, it should give us an idea on where we would find the stack in the virtual memory. 

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - print locations of various elements
 *
 * Return: EXIT_FAILURE if something failed. Otherwise EXIT_SUCCESS
 */
int main(void)
{
	int a;

	printf("Address of a: %p\n", (void *)&a);
	getchar();
	return (EXIT_SUCCESS);
}
