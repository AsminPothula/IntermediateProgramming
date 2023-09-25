//Asmin Pothula 1001904488 Coding Assignment 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "GameLib.h"

    int main(void)
    {
        char Phrase[MAX_INPUT] = {};
        char DashedPhrase[MAX_INPUT] = {};
        char UpperPhrase[MAX_INPUT] = {};
        int Strikes = 0;
        int i;
        
        StartGame (Phrase);
        DashIt (Phrase, DashedPhrase);
        
        for (int k=0; k< strlen(Phrase); k++)
        {
            UpperPhrase[k] = toupper (Phrase[k]);
        }
        printf("\nHere's the phrase you need to guess\n");
        
        do
        {
            if (!GuessALetter (Phrase, DashedPhrase, UpperPhrase))
            {
                Strikes++;
                printf("\nStrike %d", Strikes);
            }
        } while (strchr (DashedPhrase,'-') && Strikes < STRIKES);
        
            
        if (Strikes < STRIKES)
        {
            printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
            printf("\n\nYOU WIN!!!!\n");
        }
        else
        {
            printf("\n\n");
            printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
            printf("Game over\n\n");
        }
        
        return 0;
    }
