#include <stdio.h>

void setArray(int *numbers, int value, int size);
void setArray(int *numbers, int value, int size){
    int numbers[0];
    int value = 15;
    int size = 8;
    for(int i = 0; i <= size; i++){

        numbers[value];
        int *ip = &numbers;
        numbers += size;
        size++;
    }
}


int main(){


    printf("Enter a number\n");
    scanf("%d", &value);

    setArray();
    



    return 0;



}