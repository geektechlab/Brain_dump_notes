#include "arith.h"
#include <stdio.h>
#include <dlfcn.h>

 
int main()
{
	int x= 10, y = 20;
	void *handle;
	int (*fnptr)(int,int);

	handle = dlopen("../libarith.so", RTLD_NOW);
	if(handle == NULL){
        printf(" Failed to load library \n");
        exit(2);
    }

	fnptr = dlsym(handle, "add");
	printf("add:%d\n", fnptr(x, y));
	dlclose(handle);

	return 0;
}
