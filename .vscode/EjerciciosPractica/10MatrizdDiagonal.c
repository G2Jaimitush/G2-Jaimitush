#include <stdio.h>

int main (){

    int n, esDiagonal = 1;

    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &n);
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i != j && matriz[i][j] != 0)
                esDiagonal = 0;
        }

    printf("%s\n", esDiagonal ? "Es diagonal" : "No es diagonal");

    return 0;
}