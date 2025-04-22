#include <stdio.h>
int main ()
{
    int i, j,resultado;
    printf("Tablas de multiplicar del 1 al 13\n");
    i = 1;
    do{
        if (i % 2==0)
        {
            printf ("Tabla del %d \n",i);
            j = 1;
                do
                {
                    resultado = i * j;
                    if (j % 2 == 0)
                    {
                        printf ("%d X %d = %d\n",i,j,resultado);
                    }
                    j++;
                }while (j <= 10);
            printf ("\n");
        } 
        i++;
    }while (i <= 13);
    return 0;
}