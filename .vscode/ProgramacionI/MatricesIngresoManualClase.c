#include <stdio.h>

int main() {
    int i, j;
    int matriz1[3][3];
    int matriz2[3][3];
    int sumaTotal = 0;


    // Ingreso de la primera matriz
    printf("Ingrese los elementos de la primera matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Primera Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Ingreso de la segunda matriz
    printf("Ingrese los elementos de la segunda matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Segunda Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Mostrar la primera matriz
    printf("\n-------------------------\n");
    printf("Primera Matriz 3 x 3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz1[i][j]);
            sumaTotal += matriz1[i][j]; // Sumar elementos
        }
        printf("\n");
    }

    // Mostrar la segunda matriz
    printf("\n-------------------------\n");
    printf("Segunda Matriz 3 x 3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz2[i][j]);
            sumaTotal += matriz2[i][j]; // Sumar elementos
        }
        printf("\n");
    }

    // Mostrar suma total de todos los elementos
    printf ("--------------------------------\n");
    printf("La suma total de todos los elementos de ambas matrices es: %d\n", sumaTotal);
    printf("Suma de las matrices:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
