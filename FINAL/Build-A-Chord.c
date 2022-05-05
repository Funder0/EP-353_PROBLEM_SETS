#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//Excute this code using:
//clang 01.SineWave.c -o 01.SineWave -lsndfile; ./01.SineWave

#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "CustomChord.wav"

int main(void){
  SNDFILE *sndFile;
  SF_INFO sfInfo;
  double *buffer;
  int yn;
  printf("\n\nHello user! Would you like to build a chord?\n(Press 1 for YES, or 2 for NO, then press ENTER)\n");
  scanf("%i", &yn);

  switch(yn){
    case 1:
    printf("Perfect! It's easy, I'll walk you through the whole thing\n\n");

    break;
//_____________________________________________
    case 2:
    printf("Well somebody's bitter...you know what? We're gonna do it anyways!\n\n");
    break;
    default:
    printf("I didn't understand you there, make sure you're typing everything right. For now, we'll just start building it\n");
  }
  int key;

  printf("First, let's choose the key. The options we have available are;\nA Major (Press 1)\nC Major (Press 2)\nD Major (Press 3)\nF Major (Press 4)\nG Major (Press 5)\nA Minor (Press 6)\nC Minor (Press 7)\nD Minor (Press 8)\nF Minor (Press 9)\nG Minor (Press 0)\n");
  printf("Press ENTER once you've chosen\n");
  scanf("%i", &key);


  //Sound parameters
  double amplitude = 0.25;
  double frequency;
  switch(key){
    case 1://A
      printf("Yes Sir\n");
      double frequency[3] = {440, 554.37, 659.25};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (frequency[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
      
    break;
//_____________________________________________

    case 2://C
      printf("You got it!\n");
      double freqC[3] = {523.25, 659.25, 783.99};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqC[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
      
    break;
//_____________________________________________

    case 3://D
      printf("Great Choice!\n");
      double freqD[3] = {293.66, 369.99, 440};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqD[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
    break;
//_____________________________________________

   case 4://F
    printf("Amen!\n");
    double freqF[3] = {349.23, 440, 523.25};

    //Create kNumChannels worth buffer for holding audio data 
    buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
    if (!buffer){
      printf ("Error : Malloc failed.\n");
      return 1;
    };

    //Initialize SF_INFO with 0s (memset is in string.h library)
    memset(&sfInfo, 0, sizeof(SF_INFO)); 

    //Set the format for the sound file to be saved
    sfInfo.samplerate = kSampleRate;
    sfInfo.frames = kNumFrames;
    sfInfo.channels = kNumChannels;
    sfInfo.format = kFormat;

    //Open the original sound file as read mode
    sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
    if(!sndFile){
      printf ("Error : could not open file : %s\n", kFileName);
      puts(sf_strerror (NULL));
      return 1;
    }
    
    //Compute sine wave (interleave channels)
    for(int f = 0; f < 3; f++){
    for (int t = 0; t < kNumFrames; t++){
      // Compute A sin(2πft+φ). Phase is ignored in this case.
      // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
      double sample = amplitude * sin(2.0 * M_PI * (freqF[f]/kSampleRate) * t);
      // Write the same sample into all channels
      for(int c = 0; c < kNumChannels; c++){
        buffer[kNumChannels * t + c] += sample;
      }
    }
    }
    break;
//_____________________________________________

   case 5://G
    printf("Very Cool!\n");
    double freqG[3] = {392.00, 493.88, 587.33};

    //Create kNumChannels worth buffer for holding audio data 
    buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
    if (!buffer){
      printf ("Error : Malloc failed.\n");
      return 1;
    };

    //Initialize SF_INFO with 0s (memset is in string.h library)
    memset(&sfInfo, 0, sizeof(SF_INFO)); 

    //Set the format for the sound file to be saved
    sfInfo.samplerate = kSampleRate;
    sfInfo.frames = kNumFrames;
    sfInfo.channels = kNumChannels;
    sfInfo.format = kFormat;

    //Open the original sound file as read mode
    sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
    if(!sndFile){
      printf ("Error : could not open file : %s\n", kFileName);
      puts(sf_strerror (NULL));
      return 1;
    }
    
    //Compute sine wave (interleave channels)
    for(int f = 0; f < 3; f++){
    for (int t = 0; t < kNumFrames; t++){
      // Compute A sin(2πft+φ). Phase is ignored in this case.
      // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
      double sample = amplitude * sin(2.0 * M_PI * (freqG[f]/kSampleRate) * t);
      // Write the same sample into all channels
      for(int c = 0; c < kNumChannels; c++){
        buffer[kNumChannels * t + c] += sample;
      }
    }
    }
    break;
//_____________________________________________  

    case 6://A-
      printf("Nice!\n");
      double freqAm[3] = {440, 523.25, 659.25};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqAm[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }


    break;
//_____________________________________________

    case 7://C-
      printf("Ooh that one's good!\n");
      double freqCm[3] = {523.25, 622.25, 783.99};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqCm[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
    break;
//_____________________________________________

    case 8://D-
      printf("Copy!\n");
      double freqDm[3] = {293.66, 349.23, 440};
      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqDm[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
    break;
//_____________________________________________

   case 9://F-
      printf("Alright!\n");
      double freqFm[3] = {349.23, 415.30, 523.25};
      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqFm[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }
    break;
//_____________________________________________

    case 0://G-
      printf("Here we go!\n");
      double freqGm[3] = {392.00, 466.16, 587.33};

      //Create kNumChannels worth buffer for holding audio data 
      buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
      if (!buffer){
        printf ("Error : Malloc failed.\n");
        return 1;
      };

      //Initialize SF_INFO with 0s (memset is in string.h library)
      memset(&sfInfo, 0, sizeof(SF_INFO)); 

      //Set the format for the sound file to be saved
      sfInfo.samplerate = kSampleRate;
      sfInfo.frames = kNumFrames;
      sfInfo.channels = kNumChannels;
      sfInfo.format = kFormat;

      //Open the original sound file as read mode
      sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
      if(!sndFile){
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
      }
      
      //Compute sine wave (interleave channels)
      for(int f = 0; f < 3; f++){
      for (int t = 0; t < kNumFrames; t++){
        // Compute A sin(2πft+φ). Phase is ignored in this case.
        // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
        double sample = amplitude * sin(2.0 * M_PI * (freqGm[f]/kSampleRate) * t);
        // Write the same sample into all channels
        for(int c = 0; c < kNumChannels; c++){
          buffer[kNumChannels * t + c] += sample;
        }
      }
      }

    break;

  }

  printf("\nYour chord has been generated! You can open it in your Finder. Have a great day!\n");

/*
  //Create kNumChannels worth buffer for holding audio data 
  buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
  if (!buffer){
    printf ("Error : Malloc failed.\n");
		return 1;
	};

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfo, 0, sizeof(SF_INFO)); 

  //Set the format for the sound file to be saved
  sfInfo.samplerate = kSampleRate;
	sfInfo.frames = kNumFrames;
	sfInfo.channels = kNumChannels;
	sfInfo.format = kFormat;

   //Open the original sound file as read mode
  sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
  if(!sndFile){
    printf ("Error : could not open file : %s\n", kFileName);
		puts(sf_strerror (NULL));
		return 1;
  }
  
  //Compute sine wave (interleave channels)
  for(int f = 0; f < 3; f++){
  for (int t = 0; t < kNumFrames; t++){
    // Compute A sin(2πft+φ). Phase is ignored in this case.
    // frequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
    double sample = amplitude * sin(2.0 * M_PI * (frequency[f]/kSampleRate) * t);
    // Write the same sample into all channels
    for(int c = 0; c < kNumChannels; c++){
      buffer[kNumChannels * t + c] += sample;
    }
  }
  }
*/

  //Write out the result
  sf_count_t count = sf_write_double(sndFile, buffer, sfInfo.channels * kNumFrames);

  //Make sure writing the file succeeeded  
  if(count != sfInfo.channels * kNumFrames){
    puts(sf_strerror(sndFile));
  }

  //Close sound file and buffer
  sf_close(sndFile);
  free(buffer);

  return 0;
}