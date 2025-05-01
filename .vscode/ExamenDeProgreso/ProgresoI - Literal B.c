#include <stdio.h>

int main() {
    int i, j;
    int fil = 3, col = 3;
    int mat_b[3][3];

    printf("Ingrese los elementos de una matriz 3x3:\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat_b[i][j]);
        }
    }

    // Mostrar la matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", mat_b[i][j]);
        }
        printf("\n");
    }

    // Crear matriz extendida para aplicar Sarrus (3x5)
    int mat_ext[3][5];
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            mat_ext[i][j] = mat_b[i][j];
        }
        // Copiar las dos primeras columnas al final
        mat_ext[i][3] = mat_b[i][0];
        mat_ext[i][4] = mat_b[i][1];
    }

    // Calcular determinante por Sarrus
    int diag_principal = 
        (mat_ext[0][0] * mat_ext[1][1] * mat_ext[2][2]) +
        (mat_ext[0][1] * mat_ext[1][2] * mat_ext[2][3]) +
        (mat_ext[0][2] * mat_ext[1][3] * mat_ext[2][4]);

    int diag_secundaria = 
        (mat_ext[0][2] * mat_ext[1][1] * mat_ext[2][0]) +
        (mat_ext[0][3] * mat_ext[1][2] * mat_ext[2][1]) +
        (mat_ext[0][4] * mat_ext[1][3] * mat_ext[2][2]);

    int determinante = diag_principal - diag_secundaria;

    printf("\nDeterminante de la matriz: %d\n", determinante);

    return 0;
}
