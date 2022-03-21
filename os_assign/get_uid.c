#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h> 
#include<signal.h>
#include<unistd.h>

int main(int argc, char *argv[])

{
    printf("UID: %d\n",getuid()); 
    return 0;
}