#include <stdio.h>


int main(){

    

    int numbers[7] = {5, 9, 1, 2, 4, 8, 3};
    int backwards[7];

    for(int i = 0; i < 4; i++){

        numbers[i] = numbers[6 - i];
        printf("The value of arr at index %d is %d.\n", i, numbers[i]);

       
    }

    for(int i = 4; i < 7; i++){

        backwards[i] = numbers[6 - i];
        printf("The value of arr at index %d is %d.\n", i, backwards[i]);


    }

    return 0;

}