#include <stdio.h>

char *string[100];
void countCharacter(char *string);

int main(){

    
    
    printf("Enter a sentence:\n");
    scanf("%s\n", &*string);

    

    printf("The string, %c, has ___ characters\n", *string[100]);
    
    return 0;
    }