#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX_SIZE 1024
#define FIFO_PATH "/tmp/fifo"
 
 
void client(int writefd)
{
    char *buff = "hi server";
    write(writefd, buff, strlen(buff));
}
 
int main()
{
    int writefd;
 
    if (mkfifo(FIFO_PATH, 0777) < 0)
        printf("can't create %s\n", FIFO_PATH);
 
    writefd = open(FIFO_PATH, O_WRONLY);
 
    client(writefd);
 
    return 0;
}
