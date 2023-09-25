//Asmin Pothula
//1001904488

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int repeat (int randnum, int bingoarray[5][5])  
{
    int l=0;
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            if (bingoarray[i][j]==randnum)
            {
                l=1;   
            }
        }
    }
    return l;
}

void fillcard (int bingoarray[5][5]) 
{
    
    for (int i=0; i<5; i++)
    {
        for (int j =0;j<5;j++)
        {
            int randnum = rand()%15+(15*j)+1;
            int x = repeat  (randnum,bingoarray);
            if (x !=1)
            {
                bingoarray[i][j] = randnum;
            }
            else
            {
                j--;
            }
        }
    }
    bingoarray[2][2] = 0;
    
}

void printcard (int bingoarray [5][5])
{
    printf ("   \tB         I        N        G        O\n");
    printf("----------------------------------------------\n");
    for (int i=0; i<5; i++)
    {
        for (int j =0;j<5;j++)
        {
                if (bingoarray[i][j] != 0)
                {
                    printf("|  %3d   ",bingoarray[i][j]);
                }
                else
                {
                    printf ("|    X   ");
                }
            
        }
        printf("|");
        printf("\n----------------------------------------------");
        printf ("\n");
    }
}

int numberincard (int random, int bingoarray[5][5])  
{
    int x=0;
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            if (bingoarray[i][j]==random)
            {
                bingoarray[i][j] = 0;
                x=1;   
            }
            else
            {
                x=0;
            }
        }
    }
    return x;
}

int picknumber (int randomnumber[75], int counter)
{
    int random = rand()% 76;
    int m = 0;
    for (int i=0; i<75; i++)
    {
        if(randomnumber[i] == random)
        {
            while (randomnumber[m]== random)
            {
                random = rand()% 76;
                m++;
            }
            m=0;
        }
        randomnumber[i] = random;
    }
    return random;
}

char rowcomplete (int bingoarray [5][5]) 
{
    char b;
    for(int i=0;i<5;i++)
    {
       if (bingoarray[i][0]==0 && bingoarray[i][1]==0 && bingoarray[i][2]==0 && bingoarray[i][3]==0 && bingoarray[i][4]==0 )
       {
           b = 't' ;
       }
       
    }
    return b; 
}

char columncomplete (int bingoarray [5][5]) 
{
    char a ;
    for(int i=0;i<5;i++)
    {
       if (bingoarray[0][i]==0 && bingoarray[1][i]==0 && bingoarray[2][i]==0 && bingoarray[3][i]==0 && bingoarray[4][i]==0 )
       {
            a = 't';
       }
           }
    return a; 
}

char diagonalcomplete (int bingoarray [5][5]) 
{
    char c;
    if ((bingoarray[0][0]==0 && bingoarray[1][1]==0 && bingoarray[2][2]==0 && bingoarray[3][3]==0 && bingoarray[4][4]==0) || (bingoarray[0][4]==0 && bingoarray[1][3]==0 && bingoarray[2][2]==0 && bingoarray[3][1]==0 && bingoarray[4][0]==0 ))
    {
        c = 't'; 
    }
    
    return c;
}

int  main (void)
{
    srand (time(0));
    int bingoarray [5][5];
    int counter=0;
    char a, b, c; 
    int randomnumber[75];
    char answer;
    
    fillcard (bingoarray);
    while ((rowcomplete(bingoarray)!= 't' && columncomplete(bingoarray)!='t' && diagonalcomplete(bingoarray)!='t') )
    {
        printcard (bingoarray);
        
        int random = picknumber(randomnumber,counter);
        
        if (random >=1 && random <=15)
        {
            printf ("The next number is B%d\n",random);
        }
        else if (random >=16 && random <=30)
        {
            printf ("The next number is I%d\n",random);
        }
        else if (random >=31 && random <=45)
        {
            printf ("The next number is N%d\n",random);
        }
        else if (random >=46 && random <=60)
        {
            printf ("The next number is G%d\n",random);
        }
        else if (random >=61 && random <=75)
        {
            printf ("The next number is O%d\n",random);
        }
    
        printf ("Do you have it? (Y/N)");
        scanf(" %c",&answer);
        
        if (answer =='Y')
        {
            int x = numberincard (random, bingoarray);
            if (x ==0)
            {
                printf ("That value is not on your BINGO card - are you trying to cheat????\n");
                counter++;
            }
        
        	else
        	{
           		a = columncomplete (bingoarray);
                b = rowcomplete (bingoarray);
                c = diagonalcomplete (bingoarray);
                if (a=='t')
                {
                    printf ("You filled out a column - BINGO!!!\n");
                }
                else if (b =='t')
                {
                    printf ("You filled out a row - BINGO!!!\n");
                }
                else if (c =='t')
                {
                    printf ("You filled out a diagonal - BINGO!!!\n");
                }
                else if (a=='t'&& b=='t')
                {
                    printf ("You filled out a column and a row - BINGO!!!\n");
                }
                else if (a=='t'&& c=='t')
                {
                    printf ("You filled out a column and a diagonal - BINGO!!!\n");
                }
                else if (c=='t'&& b=='t')
                {
                    printf ("You filled out a row and a diagonal - BINGO!!!\n");
                }
                else if (a=='t'&& b=='t' && c=='t')
                {
                    printf ("You filled out a diagonal, a column, and a row - BINGO!!!\n");
                }
                    
            }
        }
    }
        
        
    return 0;
}
