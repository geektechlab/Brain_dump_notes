
#include <stdio.h> 
  
int global; /* Uninitialized variable stored in bss*/
  
int main(void) 
{ 
	static int i;
	global++;
    return 0; 
} 
