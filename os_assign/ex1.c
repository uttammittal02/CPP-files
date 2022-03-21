#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) 
{

    printf("PID of ex1.c = %d\n", getpid());
    char * const args[] = {"Hello", "World", "!\n", NULL};

    execv("./ex2", args);
    printf("Back to ex1.c\n");
    return 0; 
}