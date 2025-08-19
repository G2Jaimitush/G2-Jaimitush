#include <stdio.h>

int main (){

    int n, suma = 0;
 
    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &n);
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i + j == n - 1)
                suma += matriz[i][j];
        }

    printf("Suma de la diagonal secundaria: %d\\n", suma);

    return 0;
}