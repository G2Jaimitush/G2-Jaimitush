#include <stdio.h>

int main() {
    int i, j, k;
    int filas1, columnas1;
    int filas2, columnas2;

PETICION:
    // Ingreso de dimensiones
    printf("Ingrese la cantidad de filas de la primera matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese la cantidad de columnas de la primera matriz: ");
    scanf("%d", &columnas1);

    printf("Ingrese la cantidad de filas de la segunda matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese la cantidad de columnas de la segunda matriz: ");
    scanf("%d", &columnas2);

    // Verificar si se pueden multiplicar
    if (columnas1 != filas2) {
        printf("\nERROR: Para multiplicar matrices, el número de columnas de la primera debe ser igual al número de filas de la segunda.\n\n");
        goto PETICION;
    }

    // Declarar matrices
    int matriz1[filas1][columnas1];
    int matriz2[filas2][columnas2];
    int resultado[filas1][columnas2]; // Resultado será de tamaño filas1 x columnas2

    // Inicializar matriz resultado en 0
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
        }
    }

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

    // Mostrar primera matriz
    printf("\nPrimera Matriz (%d x %d):\n", filas1, columnas1);
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas1; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    // Mostrar segunda matriz
    printf("\nSegunda Matriz (%d x %d):\n", filas2, columnas2);
    for (i = 0; i < filas2; i++) {
        for (j = 0; j < columnas2; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Multiplicación de matrices
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas2; j++) {
            for (k = 0; k < columnas1; k++) { // o filas2, que es igual
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // Mostrar resultado
    printf("\n------------------------------\n");
    printf("Resultado de la multiplicación de matrices (%d x %d):\n", filas1, columnas2);
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas2; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
