#include <stdio.h> /* for perror() */
#include <stdlib.h> /* for exit() */


void DieWithError(char *errorMessage)
{
    perror (errorMessage) ;
    exit(1);
}

int main(){
    return 0;
}