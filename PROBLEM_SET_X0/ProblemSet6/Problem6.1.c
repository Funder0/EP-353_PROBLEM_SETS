#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (){

    int numBeats, numPercs;

    printf("How many beats would you like Sir?\n");
    scanf("%d", &numBeats);

    printf("How many percs would you care for?\n");
    scanf("%d", &numPercs);

    char *sequence;
    malloc(sizeof(char) * numBeats * numPercs);

    for (int perc = 0; perc < numPercs; perc++) {
    for (int beat = 0; beat < numBeats; beat++) {
      printf("beat: %d, perc: %d, state: %d, index: %d\n", 
        beat, perc, sequence[perc * numBeats + beat], perc * numBeats + beat);
    }
  }
    srand(numBeats * numPercs);

    printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  \n==+===+===+===+===+===+===+===+===+\n1 |   |   |   |   |   |   |   |   |\n");

    free(sequence);

    return 0;


}