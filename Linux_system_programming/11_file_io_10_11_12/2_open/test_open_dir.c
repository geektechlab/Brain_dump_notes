#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/* Since everything is file in linux, we can open directory as well */
/* We can open directory only in read only mode. Write only modde is not allowed */

int main()
{
    int fd;
    if ((fd = open("/home/panther2", O_DIRECTORY | O_RDONLY)) ==-1)
    //if ((fd = open("/home/panther2",  O_WRONLY)) ==-1)
    {
        printf("error %s\n", strerror(errno));
       return -1;
    }
    return 0;
}
