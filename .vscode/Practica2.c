#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;

    // Ingreso de la matriz
    printf("Ingrese los elementos de una matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Aplicación del método de Sarrus
    int diag_principal = 
        matriz[0][0] * matriz[1][1] * matriz[2][2] +
        matriz[0][1] * matriz[1][2] * matriz[2][0] +
        matriz[0][2] * matriz[1][0] * matriz[2][1];

    int diag_secundaria = 
        matriz[0][2] * matriz[1][1] * matriz[2][0] +
        matriz[0][0] * matriz[1][2] * matriz[2][1] +
        matriz[0][1] * matriz[1][0] * matriz[2][2];

    int determinante = diag_principal - diag_secundaria;

    // Resultado
    printf("El determinante de la matriz es: %d\n", determinante);

    return 0;
}
