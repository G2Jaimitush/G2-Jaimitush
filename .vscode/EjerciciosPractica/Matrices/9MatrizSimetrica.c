#include <stdio.h>

int main (){

    int n, simetrica = 1;

    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &n);
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    for (int i = 0; i < n && simetrica; i++)
        for (int j = 0; j < n; j++)
            if (matriz[i][j] != matriz[j][i])
                simetrica = 0;

    printf("%s\n", simetrica ? "Es simetrica" : "No es simetrica");

    return 0;
}