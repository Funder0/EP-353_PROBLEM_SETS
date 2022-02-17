#include <stdio.h>


char pitches[8] = {74, 68, 54, 28, 89, 51, 35};



int main(){

    char pitch;
    char index;

    printf("Please choose a number between 0 and 127\n");

    scanf("%c", &pitch);

    printf("Now...pick a number between 0 and 7");

    scanf("%c", &index);

    printf("The new pitches are:\n\t");

    for(int i = 0; i < index; i++){

        printf("%c ", pitches[i]);
    }

    for(int j = index + 1; j < 8; j++){

        pitches[i];

        pitches[j] = pitches[i + 1];

        printf("%c ", pitches[j]);
    }

    printf("\n");

    return 0;


}

