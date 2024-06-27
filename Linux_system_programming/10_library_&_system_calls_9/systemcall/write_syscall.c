#include <unistd.h>
int main(){
   char str[]={"Welcome to System Programming...\n"};
	//printf("strlen:%d\tsizeof:%d\n", strlen(str), sizeof(str));
	int rv = write(1, str, sizeof str); 
   return 0;
}

