//Asmin Pothula
//1001904488

#include <stdio.h>
#define BITS 8

void ConvertDecimalToBinary(int x, char binary[])
{
    int bytwo[BITS]={};
    bytwo[0]= x;
    for (int i=1;i<BITS; i++)
    {
        bytwo[i]= bytwo[i-1] >>1;
    }
    
    int i=0;
    for (int j=(BITS-1);j>=0; j--)
    {
        if (bytwo[i] & 1) 
        {
            binary[j] = '1';
            i++;
        }
            
        else
        {
            binary[j] = '0';
            i++;
        }
    }
    return;
}
int main(void)
{
    int a,b;
    char operator[3],binarya[BITS+1]={}, binaryb[BITS+1]={}, binaryresult[BITS+1]={};
    printf  ("\nBitwise Calculator\n");
    printf  ("\nEnter two base 10 values with a bitwise operator to see the decimal result and the binary result. The format is\n\nFirstNumber BitwiseOperator SecondNumber \n\nFor example, enter the expression \n\n2 & 3 \n\nThis calculator can used with &, |, ^, << and >> \n\nPlease note that the spaces between numbers and operator is essential and the two entered values must be between 0 and 255\n\n");
    
    printf ("Enter expression:");
    scanf("%d %s %d",&a,operator,&b);
    
    while (a<0 || b>255 || a>255 || b<0)
    {
        printf ("\nThe entered expression contains out of range values.\nPlease reenter the expression using values between 0 and 255.\n\n");
        scanf("%d %s %d",&a,operator,&b);
    }
    
    ConvertDecimalToBinary(a, binarya);
    ConvertDecimalToBinary(b, binaryb);
    
    if (operator[0] == '&')
    {
        int c = a&b;
        printf ("\nIn base 10...\n\n");
        printf ("%d %s %d = %d\n\n\n",a,operator,b,c);
        printf ("In %d-bit base 2...\n\n",BITS);
        printf ("   %s\n",binarya);
        printf ("%s\n",operator);
        printf ("   %s\n",binaryb);
        printf ("   ========\n");
        ConvertDecimalToBinary(c, binaryresult);
        printf ("   %s\n\n",binaryresult);
        
    }
    else if (operator[0] == '|')
    {
        int c = a|b;
        printf ("\nIn base 10...\n\n");
        printf ("%d %s %d = %d\n\n\n",a,operator,b,c);
        printf ("In %d-bit base 2...\n\n",BITS);
        printf ("   %s\n",binarya);
        printf ("%s\n",operator);
        printf ("   %s\n",binaryb);
        printf ("   ========\n");
        ConvertDecimalToBinary(c, binaryresult);
        printf ("   %s\n\n",binaryresult);
    }
    else if (operator[0] == '^')
    {
        int c = a^b;
        printf ("\nIn base 10...\n\n");
        printf ("%d %s %d = %d\n\n\n",a,operator,b,c);
        printf ("In %d-bit base 2...\n\n",BITS);
        printf ("   %s\n",binarya);
        printf ("%s\n",operator);
        printf ("   %s\n",binaryb);
        printf ("   ========\n");
        ConvertDecimalToBinary(c, binaryresult);
        printf ("   %s\n\n",binaryresult);
    }
    else if (operator[0] == '<')
    {
        int c = a<<b;
        printf ("\nIn base 10...\n\n");
        printf ("%d %s %d = %d\n\n\n",a,operator,b,c);
        printf ("In %d-bit base 2...\n\n",BITS);
        printf ("%s  %s %d\n\n",binarya,operator,b);
        ConvertDecimalToBinary(c, binaryresult);
        printf ("%s\n\n",binaryresult);
    }
    else if (operator[0] == '>')
    {
        int c = a>>b;
        printf ("\nIn base 10...\n\n");
        printf ("%d %s %d = %d\n\n\n",a,operator,b,c);
        printf ("In %d-bit base 2...\n\n",BITS);
        printf ("%s  %s %d\n\n",binarya,operator,b);
        ConvertDecimalToBinary(c, binaryresult);
        printf ("%s\n\n",binaryresult);
    }
    else
    {
        printf ("\nOperator %s is not supported by this calculator\n\n",operator);
    }

    return 0;
}

    
    
    





