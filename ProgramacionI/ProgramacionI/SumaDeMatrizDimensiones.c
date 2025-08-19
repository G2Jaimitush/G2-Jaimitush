#include <stdio.h>

int main() {
    int i, j;
    int filas1, columnas1;
    int filas2, columnas2;

    // Solicitar dimensiones de la primera matriz
    PETICION:
    printf("Ingrese la cantidad de filas de la primera matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese la cantidad de columnas de la primera matriz: ");
    scanf("%d", &columnas1);

    // Solicitar dimensiones de la segunda matriz
    printf("Ingrese la cantidad de filas de la segunda matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese la cantidad de columnas de la segunda matriz: ");
    scanf("%d", &columnas2);

    // Verificar que las dimensiones coincidan
    if (filas1 != filas2 || columnas1 != columnas2) {
        printf("\nERROR: Las matrices deben tener la misma cantidad de filas y columnas para poder sumarse.\n");
        goto PETICION;
    }

    // Crear matrices con tamaño dinámico según lo ingresado
    int matriz1[filas1][columnas1];
    int matriz2[filas2][columnas2];
    int sumaTotal = 0;

    // Ingreso de la primera matriz
    printf("\nIngrese los elementos de la primera matriz:\n");
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas1; j++) {
            printf("Primera Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Ingreso de la segunda matriz
    printf("\nIngrese los elementos de la segunda matriz:\n");
    for (i = 0; i < filas2; i++) {
        for (j = 0; j < columnas2; j++) {
            printf("Segunda Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Mostrar la primera matriz
    printf("\n-------------------------\n");
    printf("Primera Matriz %d x %d:\n", filas1, columnas1);
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas1; j++) {
            printf("%d ", matriz1[i][j]);
            sumaTotal += matriz1[i][j];
        }
        printf("\n");
    }

    // Mostrar la segunda matriz
    printf("\n-------------------------\n");
    printf("Segunda Matriz %d x %d:\n", filas2, columnas2);
    for (i = 0; i < filas2; i++) {
        for (j = 0; j < columnas2; j++) {
            printf("%d ", matriz2[i][j]);
            sumaTotal += matriz2[i][j];
        }
        printf("\n");
    }

    // Mostrar suma total
    printf("\n--------------------------------\n");
    printf("La suma total de todos los elementos de ambas matrices es: %d\n", sumaTotal);

    // Mostrar matriz suma
    printf("\nSuma de las matrices (elemento a elemento):\n");
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas1; j++) {
            printf("%d ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
