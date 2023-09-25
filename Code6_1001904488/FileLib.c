// Asmin Pothula 1001904488 FileLib Template

#include <stdio.h>
#include <string.h>
#include "ListLib.h"

/* return type OpenFile( parameters )*/
FILE *OpenFile(int argc, char *argv[])
{
    /* declare various variables needed */
    FILE *DCFile;
    char filename[20] = {};

    /* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
    if(argc == 2)
    {
        strcpy (filename, argv[1]);
    }
    else
    {
        printf ("Must be run with an input file name.\n");
              
    }
    do
    {
        /* open file with "r" mode */
        DCFile = fopen(filename, "r");
        /* if file did not open */
        if (DCFile == NULL)
        {
            /* print message seen in sample output */
            printf ("Enter a file name at the prompt ");
            scanf ("%s", filename);
            DCFile = fopen(filename, "r");
            if(DCFile==NULL)
            {
              printf("Could not open the input file named %s\n",filename);
            }
            /* read in new filename */
            /* open the file "r" mode */
            
        }
    }
    while (DCFile == NULL);
    //while (/* file is not open */)
        
    /* return the file handle */
    return DCFile;
}


/* return type  ReadFileIntoLinkedList( parameters )*/
void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
    /* declare various variables needed */
    char FileLine[200];
    char *token = NULL;
    char Letter;
    char DrawCommand[100];
    
    /* while fgets() reads the file */
    while (fgets(FileLine, sizeof(FileLine)-1, DCFile))
    {
        /* if line from file ends with \n, then replace \n with \0 */
        if (FileLine[strlen(FileLine)-1] == '\n')
        {
            FileLine[strlen(FileLine)-1] = '\0';
        }
        
        /* tokenize to get the Letter and the DrawCommand */
        
        Letter = *strtok(FileLine, "|");
        
        
        token = strtok(NULL,"|");
        strcpy(DrawCommand, token);
    
        /* Call AddDrawCommandToList with correct parameters */
        AddDrawCommandToList(Letter, DrawCommand, LinkedListHead);
    }
    
}


