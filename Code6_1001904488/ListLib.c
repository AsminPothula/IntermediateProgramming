/* Asmin Pothula 1001904488 */
#include <stdlib.h>
#include <string.h>
#include "ListLib.h"

/* add return type AddDrawCommandToList( Add parameters )*/
void AddDrawCommandToList(char letter, char Drawcommand[], NODE **LinkedListHead)
{
    /* declare pointers of type NODE named TempPtr and NewNode */
    NODE *TempPtr, *NewNode;
    
    /* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */
    NewNode = malloc (sizeof (NODE));
    NewNode->Letter = letter;
    NewNode->DrawCommand=malloc(sizeof(char)*strlen(Drawcommand)+1);
    strcpy(NewNode->DrawCommand,Drawcommand);
    NewNode->next_ptr = NULL;

    /* If the LinkedListHead is NULL, then give it the address of the new node */
    TempPtr=*LinkedListHead;
    if (*LinkedListHead == NULL)
    {
        *LinkedListHead = NewNode;
    }
    /* Else traverse to the end of the linked list and add the new node */
    else
    {
        while (TempPtr->next_ptr != NULL)
        {
            TempPtr = TempPtr->next_ptr;
        }
        TempPtr->next_ptr = NewNode;
    }
}


NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
    /* while traversing the linked list AND the Letter in the node is not the Letter passed in */
    NODE *TempPtr = LinkedListHead;
    while (TempPtr != NULL && (TempPtr->Letter != Letter))
    {
        /* move TempPtr */
        TempPtr = TempPtr->next_ptr;
    }

    //if (/* TempPtr is not NULL */)
    if (TempPtr != NULL)
    {
        /* copy the DrawCommand from the node into the passed in parameter */
        strcpy(DC, TempPtr->DrawCommand);
        /* return the next pointer stored in TempPtr */
        return TempPtr->next_ptr;
    }
    else
    {
        memset(DC, '\0', sizeof(*DC));  //Set DC to NULLs to signal that we found all of the nodes for this letter
        /* return TempPtr */
        return TempPtr;
    }
}

