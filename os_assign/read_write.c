#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    FILE *fptr;
    fptr = fopen("/Users/uttammittal02/Desktop/Cpp_files/os_assign/open.txt", "w");
    if (fptr == NULL){
        printf("Error! cannot open file");
        exit(1);
    }
    printf("Write a number to add in the text file: ");
    scanf("%d",&num);
    fprintf(fptr,"%d",num);
    fclose(fptr);
    fptr = fopen("/Users/uttammittal02/Desktop/Cpp_files/os_assign/open.txt","r");
    if (fptr == NULL) {
        printf("Error! Cannot open file");
        exit(1); 
    }
    fscanf(fptr,"%d", &num);
    printf("Value of n=%d", num);
    fclose(fptr);
    return 0; 
}