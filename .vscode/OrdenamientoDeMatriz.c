#include <stdio.h>

int main () {
    int i, j, k;
    int Filas1, Columnas1;

    // Entrada de dimensiones
    printf("Ingrese el numero de filas de la matriz 1: ");
    scanf("%d", &Filas1);
    printf("Ingrese el numero de columnas de la matriz 1: ");
    scanf("%d", &Columnas1);

    int matriz1[Filas1][Columnas1];
    int total = Filas1 * Columnas1;
    int vector[total];  // Vector temporal para almacenar la matriz

    // Ingreso de elementos de la matriz
    printf("\nIngrese los elementos de la matriz 1:\n");
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas1; j++) {
            printf("Matriz 1 [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Mostrar matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas1; j++) {
            printf("%d\t", matriz1[i][j]);
        }
        printf("\n");
    }

    //Convertir matriz a vector
    int index = 0;
    for (i = 0; i < Filas1; i++){
        for (j = 0; j < Columnas1; j++){
            vector [index++] = matriz1 [i][j];
        }
    }

    //Ordenar el vector de mayor a menor
    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            if (vector[i] < vector[j]) {
                int temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }

    //Reconstruir matriz desde el vector
    index = 0;
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas1; j++) {
            matriz1[i][j] = vector[index++];
        }
    }

    // Mostrar matriz ordenada
    printf("\nMatriz ordenada de mayor a menor\n");
    for (i = 0; i < Filas1; i++) {
        for (j = 0; j < Columnas1; j++) {
            printf("%d\t", matriz1[i][j]);
        }
        printf("\n");
    }

    return 0;
}