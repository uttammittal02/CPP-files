#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>

int main() { 
    printf("prior to setuid (), uid-%d, effective uid=%d\n", (int) getuid(), (int) geteuid()); 
    if (setuid(1000) == 0)
        printf("UID set to 1000\n");
    else
        printf("Failed to assign UID\n");
    return 0;
} 