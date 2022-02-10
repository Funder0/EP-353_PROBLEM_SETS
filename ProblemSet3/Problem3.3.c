#include <stdio.h>

int main(){

    int number;
    int start;

    printf("Enter an integer value...\n(Type number here) ");


    scanf("%d", &number);

    for(start = 1; start <= number; start += 2) {

        printf("%d ", start);
    }

    return 0;
}

