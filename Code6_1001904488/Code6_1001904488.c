//Asmin Pothula 1001904488

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.h"
#include "ListLib.h"
#include "FileLib.h"
#define MAXMAPSIZE 20

int main(int argc, char *argv[])
{
    char map[MAXMAPSIZE][MAXMAPSIZE];
    //char draw[100];
    char *commandToken;
    char *token;
    char drawcommand[20];
    char mark;
    char command[4];
    char rowcommand[4];
    char colcommand[4];
    char positioncommand[4];
    char markcommand[4];
    char LetterInputs[5];
    char Letter;
    int row, col, position;
//int *address = &MAXMAPSIZE;
    //int argc;
    //char *argv[4] = {};
    FILE *DCFile;
    
    //NODE **LinkedListHead = NULL;
    NODE *LinkedListHead = NULL;
    NODE *TempPtr;

    
    DCFile = OpenFile(argc,argv);
    ReadFileIntoLinkedList(DCFile,&LinkedListHead);
    
    //AddDrawCommandToList(Letter,drawcommand, LinkedListHead);
    InitializeMap(map);
    //PrintInstructions();
    PrintMap(map);
    
    printf("Please enter 1-3 letters ");
    scanf("%s", LetterInputs);
  
  
    for (int i = 0; i<strlen(LetterInputs); i++)
    {
        Letter = toupper(LetterInputs[i]);
        char draw[100] =  {};
        TempPtr= FindLetter(TempPtr, Letter, draw);

      
      while(strlen(LetterInputs)<1 || strlen(LetterInputs)>3)
      {
        printf("There should only be a maximum of 3 letters.\nPlease re-enter the letters ");
        scanf("%s", LetterInputs);
      }
    
      for(int i=0; i<strlen(LetterInputs); i++)
      {
        LetterInputs[i] = toupper(LetterInputs[i]);
      }
    
      for(int i=0; i<strlen(LetterInputs); i++)
      {
        Letter = LetterInputs[i];
        TempPtr = FindLetter(LinkedListHead, Letter, draw);
        
        while(draw[0] != '\0')
        {
            token = strtok(draw,"(,)");
            strcpy(drawcommand ,token);

            token = strtok(NULL,"(,)");
            strcpy(rowcommand, token);
            row = atoi(rowcommand);

            token = strtok(NULL,"(,)");
            strcpy (colcommand, token);
            col = atoi(colcommand);

            token = strtok(NULL,"(,)");
            strcpy (positioncommand, token);
            position = atoi(positioncommand);
            
            token = strtok(NULL,"(,)");
            strcpy (markcommand, token);
            
            /*if(strcmp(markcommand,"")==0)
            {
                strcpy(markcommand, "X");
            }*/
            if(i==1)
            {
                col = col + 7;
            }
            if(i==2)
            {
                col = col + 14;
            }
            drawcommand[0] = toupper(drawcommand[0]);
            
            if((drawcommand[0] == 'H' && (((col + position) > MAXMAPSIZE) || (row > MAXMAPSIZE))))
            {
                printf("That Draw Command is out of range.\n");
            }
            else if((drawcommand[0] == 'P' && ((col > MAXMAPSIZE) || (row > MAXMAPSIZE))))
            {
                printf("That Draw Command is out of range.\n");
            }
            else if((drawcommand[0] == 'V' && (((row + position) > MAXMAPSIZE) || (col > MAXMAPSIZE))))
            {
                printf("That Draw Command is out of range.\n");
            }
            
            else
            {
                DrawLine(map, row, col, drawcommand[0], position, markcommand[0]);
                PrintMap(map);
            }
            TempPtr= FindLetter(TempPtr, Letter, draw);
            
        }
    }
    
    return 0;
  }
}
