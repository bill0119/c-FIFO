#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX_SIZE 1024
#define FIFO_PATH "/tmp/fifo"
 
void server(int readfd)
{
    char buff[MAX_SIZE] = {0};
    int n = read(readfd, buff, MAX_SIZE);
    if (n > 0) {
        printf("read from client:%s\n", buff);
    }
}
 
int main()
{
    int readfd;
 
    if (mkfifo(FIFO_PATH, 0777) < 0)
        printf("can't create %s\n", FIFO_PATH);
    
    printf("create fifo\n");
 
    readfd = open(FIFO_PATH, O_RDONLY, 0);
    
    unlink(FIFO_PATH);
 
    server(readfd);
 
    return 0;
}