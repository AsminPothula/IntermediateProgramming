//Asmin Pothula 1001904488
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.h"
    
int main()
{
    char map[MAXMAPSIZE][MAXMAPSIZE];
    char draw[100];
    char *commandToken;
    char *token;
    char drawcommand;
    char mark;
    char command[4];
    char rowcommand[4];
    char colcommand[4];
    char positioncommand[4];
    char markcommand[4];

    int row, col, position;
    // initialize the mapsize to 0 as InitializeMap function will input the size
    int mapsize = 0;

    
    InitializeMap(map, &mapsize);
    PrintInstructions();
    PrintMap(map, mapsize);
    printf("Enter draw command (enter Q to quit) :");
    fgets(draw, 99, stdin);

    token = strtok(draw,"(,)");
    strcpy(command, token);
    drawcommand = toupper(command[0]);
    
    while (drawcommand != 'Q')
    {
        if (drawcommand == 'P' || drawcommand == 'V' || drawcommand == 'H')
        {
            token = strtok(NULL,"(,)");
            strcpy(rowcommand, token);
            row = atoi(rowcommand);
            if (row >= mapsize)
            {
                printf("That draw command is out of range.\n");
            }

            token = strtok(NULL,"(,)");
            strcpy (colcommand, token);
            col = atoi(colcommand);
            if (col >= mapsize )
            {
                printf("That draw command is out of range.\n");
            }

            token = strtok(NULL,"(,)");
            strcpy (positioncommand, token);
            position = atoi(positioncommand);

            token = strtok(NULL,"(,)");
            strcpy (markcommand, token);
            
            if (strcmp(&markcommand[0], "\0")==1)
            {
                mark = 'X';
            }
            else
            {
                mark = *markcommand;
            }

            if (drawcommand == 'P')
            {
                map[row][col] = mark;
            }
            else if (drawcommand == 'V')
            {
                if ((row) > (mapsize))
                {
                    printf("That draw command is out of range.\n");
                }
                else
                {
                    DrawLine(map, row, col, drawcommand, position, mark);
                }
            }
            else if (drawcommand == 'H')
            {
                if ((position + col) > (mapsize))
                {
                    printf("That draw command is out of range.\n");
                }
                else
                {
                    DrawLine(map, row, col, drawcommand, position, mark);
                }
            }
            else if (drawcommand == 'V')
            {
                if ((position + col) > (mapsize))
                {
                    printf("That draw command is out of range.\n");
                }
                else
                {
                    DrawLine(map, row, col, drawcommand, position, mark);
                }
            }
        }
        else
        {
            printf("The draw command is unknown.\n");
        }
        PrintMap(map, mapsize);
        printf("Enter draw command (enter Q to quit) : ");
        fgets(draw, 99, stdin);
        token = strtok(draw,"(,)");
        drawcommand = toupper(token[0]);
    }
    return 0;
}
