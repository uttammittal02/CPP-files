#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    printf("Entered into process\n");

    fork();
    kill(getpid(), 1);
    return 0;
}