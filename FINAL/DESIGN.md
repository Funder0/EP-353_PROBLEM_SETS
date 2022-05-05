## Design
My design of Build-A-Chord was a series of scanf questions to give the user choices of what kind of chord they want. I wanted it to almost feel like the user was shopping for a candy bar and had options flavors. 

The idea was to show that I can implememnt a working code for a polyphonic sound file. The idea of scanf was to give ten options for the code. 

In this code, I used switch statements to customize the frequencies to the needs of the user. I was able to do this by copying each code into each switch statement, only slightly changing it each time.

The pronblem I was running into was that the values in the frequency array could not be changed once I declared them the forst time. My solution was to create variable names for each chord. For example, if it was an A Minor chord, I would set the array as `freqAm[3]` and set the values as the corresponding frequencies.

The easiest way to make the scanf work for me was to have the user input numbers instead of typing `YES` or `A Major`. This was just an effort to try to minimize the possibility of user error.

When I ran my code it worked, but I want to go even further. I want to eventually make it so the user can change the parameters (ADSR), wave type (sine, saw, etc.), and durstion (long, short). This could give producers and artists an easy way to sound design without having to know how to work actual synthesizers.