#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){
  //print hello world to a file with dup
  int fd;

  //check args
  if ( argc < 2){
    fprintf(stderr, "ERROR: Require destination path\n");
    return 1;
  }

  //open destination file
  if( (fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT , 0644)) < 0){
    perror("open");
    return 1;
  }

  //close standard out
  close(1);

  //duplicate fd to stdout
  dup2(fd, 1);

  //print to stdout, which is now duplicated to fd
  printf("Hello World!\n");
  printf("value = %d\n", 5);
  write(fd, "Linux", 5);

  return 0;
}
