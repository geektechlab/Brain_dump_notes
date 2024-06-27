#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	char strbuf[BUFSIZ];
	char *ptr;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (stat(argv[1], &buf) < 0) {
		perror("stat error");
		exit(EXIT_FAILURE);
	}

	snprintf(strbuf, BUFSIZ, "%s: ", "File set-user-ID");

	if (buf.st_mode & S_ISUID)
		ptr = "TRUE\n";
	else
		ptr = "FALSE\n";
	strncat(strbuf, ptr, BUFSIZ-strlen(strbuf));
	printf("%s", strbuf);

	snprintf(strbuf, BUFSIZ, "%s: ", "File set-group-ID");
	if (buf.st_mode & S_ISGID)
		ptr = "TRUE\n";
	else
		ptr = "FALSE\n";
	strncat(strbuf, ptr, BUFSIZ-strlen(strbuf));
	printf("%s", strbuf);

	exit(EXIT_SUCCESS);
}
	
