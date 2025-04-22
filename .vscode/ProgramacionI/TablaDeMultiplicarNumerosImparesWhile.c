#include <stdio.h>

int main()
{
    int i,j,resultado;
    printf ("Tabla des Multiplicacion del 1 - 13\n");
    i = 1;
    while (i<=13){
        if (i % 2 == 1)
        {
            printf ("Tabla del %d: \n",i);
            j = 1;
            while (j <=10){
                if (j % 2 == 1)
                {
                    resultado = i * j;
                    printf ("%d X %d = %d\n", i,j, resultado);
                }
                j++;
            }
        }
        printf ("\n");
        i++;
    }
    return 0;
}