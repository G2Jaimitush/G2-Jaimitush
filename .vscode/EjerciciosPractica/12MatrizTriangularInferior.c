#include <stdio.h>

int main (){

    int n, esInferior = 1;

    printf("Ingrese tamaño de la matriz cuadrada: ");
    scanf("%d", &n);
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i < j && matriz[i][j] != 0)
                esInferior = 0;
        }

    printf("%s\n", esInferior ? "Es triangular inferior" : "No lo es");

    return 0;
}