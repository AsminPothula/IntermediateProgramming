// Asmin Pothula 1001904488

#include <stdio.h>

int main (void)
{
    int istart=0, iend=0, jstart=0, jend=0, kstart=0, kend=0;

    printf ("Enter starting value of i: ");
    scanf ("%d",&istart);
    printf ("Enter ending value of i: ");
    scanf ("%d",&iend);

    printf ("Enter starting value of j: ");
    scanf ("%d",&jstart);
    printf ("Enter ending value of j: ");
    scanf ("%d",&jend);

    printf ("Enter starting value of k: ");
    scanf ("%d",&kstart);
    printf ("Enter ending value of k: ");
    scanf ("%d",&kend);

    for (int i=istart; i<iend; i++)
    {
        for (int j=jstart; j<jend; j++)
        {
            for (int k=kstart; k<kend; k++)
            {
                printf ("* ");
            }
            printf ("\n");
        }
        printf ("\n\n");
    }
    return 0;
}
