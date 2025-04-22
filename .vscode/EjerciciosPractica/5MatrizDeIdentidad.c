#include <stdio.h>

int main (){
    
    int n, esIdentidad = 1;
    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &n);
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0))
                esIdentidad = 0;
        }

    if (esIdentidad)
        printf("Es una matriz identidad\n");
    else
        printf("No es una matriz identidad\n");

    return 0;
}