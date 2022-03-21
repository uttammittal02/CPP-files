#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main() {

    // int fd1 = open("open.txt", O_RDONLY);
    int fd1 = open("non_existant.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("c1");
        exit(0); 
    }
    printf("opened the fd = % d\n", fd1);
    if (close(fd1) < 0)
    {
        perror("c1");
        exit(0); 
    }
    printf("closed the fd.\n");
}
