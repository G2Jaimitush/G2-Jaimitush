#include <stdio.h>
int main ()
{
    int i, j, resultado;
    printf("Tablas de multiplicar del 1 al 13\n");
    for (i = 1; i <= 13; i++)
    {
        printf("Tabla del %d:\n", i);
        for (j = 1; j <= 10; j++)
        {
            resultado = i * j;
            printf("%d x %d = %d\n", i, j, resultado);
        }
        printf("\n");
    }
    return 0;
}