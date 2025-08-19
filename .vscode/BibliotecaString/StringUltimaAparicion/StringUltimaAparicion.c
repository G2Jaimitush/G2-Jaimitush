#include <stdio.h>
#include <string.h>
int main()
{
    char abecedario [] = "abcdefghijklmnopqrstuvwxyz";
    char corte;
    
    printf ("Letra donde se encuentra el abecedario: ");
    fflush (stdin);
    scanf ("%c",&corte);
    
    printf ("\n%s",strrchr(abecedario,corte));
    return 0;
}