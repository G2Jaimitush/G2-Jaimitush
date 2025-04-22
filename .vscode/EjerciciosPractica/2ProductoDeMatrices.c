#include <stdio.h>

int main() {
    int i, j, k;
    int Filas1, Columnas1;
    int Filas2, Columnas2;

VERIFICACION:
    // Dimensiones de la primera matriz
    printf("Ingrese el numero de filas de la matriz 1: ");
    scanf("%d", &Filas1);
    printf("Ingrese el numero de columnas de la matriz 1: ");
    scanf("%d", &Columnas1);

    // Dimensiones de la segunda matriz
    printf("Ingrese el numero de filas de la matriz 2: ");
    scanf("%d", &Filas2);
    printf("Ingrese el numero de columnas de la matriz 2: ");
    scanf("%d", &Columnas2);

    // Verificación
    if (Columnas1 != Filas2) {
        printf("\nERROR: Las columnas de la matriz 1 deben coincidir con las filas de la matriz 2.\n");
        goto VERIFICACION;
    }

    int matriz1[Filas1][Columnas1];
    int matriz2[Filas2][Columnas2];
    int producto[Filas1][Columnas2];

    // Ingreso de datos
    printf("Ingrese los valores de la matriz 1:\n");
    for (i = 0; i < Filas1; i++)
        for (j = 0; j < Columnas1; j++) {
            printf("Matriz 1 [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }

    printf("Ingrese los valores de la matriz 2:\n");
    for (i = 0; i < Filas2; i++)
        for (j = 0; j < Columnas2; j++) {
            printf("Matriz 2 [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }

    // Inicializa matriz producto
    for (i = 0; i < Filas1; i++){
        for (j = 0; j < Columnas2; j++){
            producto[i][j] = 0;
        }
    }

    // Producto de matrices
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas2; j++) {
            for (k = 0; k < Columnas1; k++) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // Mostrar resultado
    printf("Producto de las matrices:\n");
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas2; j++) {
            printf("%d ", producto[i][j]);
        }
        printf("\n");
    }

    return 0;
}
