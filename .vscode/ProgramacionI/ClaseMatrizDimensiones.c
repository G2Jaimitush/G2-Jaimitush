#include <stdio.h>
//Primero se llenan las columnas de la primera fila
int main() {
    // Primera Matriz Declarada
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int i, j, suma = 0;
    int m2[3][3]; // Corregido tamaño de la matriz

    // Segunda Matriz ingresada por el Usu9ario
    for (i = 0; i < 3; i++) { // Maneja las filas
        for (j = 0; j < 3; j++) { // Maneja las columnas
            printf("Matriz 2 [%d][%d] = ", i, j);
            scanf("%d", &m2[i][j]);
        }
        printf("\n");
    }

    // Mostrar la Matriz 4 x 4
    printf("Matriz 4 x 4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
            suma += matriz[i][j]; // Sumar los elementos de la matriz 4x4	
        }
        printf("\n");
    }

    // Mostrar la Matriz 3 x 3
    printf("Matriz 3 x 3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m2[i][j]);
            suma += m2[i][j]; // Sumar los elementos de la matriz 3x3
        }
        printf("\n");
    }

    // Sumar las dos matrices
    printf("Suma de las matrices es: %d\n",suma);
    


    return 0;
}

