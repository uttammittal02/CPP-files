#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>


int main() 
{ int return_value;
 
		 fork();
         printf("Hello World\n");
         return 0;
		
}
