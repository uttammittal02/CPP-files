#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    printf("We are in ex2.c now!\n"); 
    printf("PID of ex2.c = %d\n", getpid()); 
    return 0;
}