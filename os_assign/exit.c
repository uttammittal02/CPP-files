#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    if (2 == 2)
    {
        printf("Exiting...");
        exit(0);
    }
    printf("If exit didn't close the program then this msg will show up!\n"); 
    return 0;
}