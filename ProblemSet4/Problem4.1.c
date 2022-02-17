#include <stdio.h>

int bar;
char *i;
void beatbox();

void beatbox(){
    
    char *i[4] = {"Boots N Cats N", "Boots N Cats N", "Boots N Cats N", "Potato Cats!"};

    printf("%s\n", *i);
}

int main(){

    printf("How many lines would you like sir?\n");

    scanf("%d", &bar);

    for(int i = 0; i < bar; i++){
        
        beatbox();
        
    }

    return 0;
}