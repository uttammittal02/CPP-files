#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h>

int main()

{

    pid_t cpid;
    printf("Entered the program\n");
    if (fork() == 0) {
        printf("Child's hello\n");
        exit(0);
    }
    else{
        printf("Parent pid=%d\n", getpid()); 
        cpid = wait(NULL); /* reaping parent */ 
        printf("Child pid=%d\n", cpid);
    }

    return 0;
}