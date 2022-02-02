#include <stdio.h>
#include <math.h>

int main(){

    double semi;
    double c0;
    double c8;
    int midinote;
    float frequency;

    semi = pow(2, 1/12.0);
    c8 = 220.0 * pow(semi, 3);
    c0 = c8 * pow(0.5, 5);

    midinote = 108;
    frequency = c0 * pow(semi, midinote);

    printf("The frequency of MIDI note number %i is %4.1f Hz.\n", midinote, frequency);

    
    return 0;
}