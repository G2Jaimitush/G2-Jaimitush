#include <stdio.h>
int main ()
{
    int i, j, resultado;
    printf ("BUCLE FOR\n");
    printf("Tablas de multiplicar\n");
    for (i = 1; i <= 13; i++)
    {
        if (i % 2 == 0) { 
            printf("Tabla del %d:\n", i);
                for (j = 1; j <= 10; j++)
            {
                resultado = i * j;
                if (j % 2 == 0) { 
                printf("%d x %d = %d\n", i, j, resultado);
            }
            }
            printf("\n"); 
            }
    }
    
    return 0;
}