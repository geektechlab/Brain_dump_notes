#include <unistd.h>
#include <stdlib.h>

/* this creates your own shell executing each typed command */
int main(int argc, char**argv) {
	char buf[10];
	while(1) {
		printf(">");
		memset(buf, 0, sizeof(buf));
		scanf("%s", buf);
  		system(buf);
		printf("\n");
	}
  return 0;
}

