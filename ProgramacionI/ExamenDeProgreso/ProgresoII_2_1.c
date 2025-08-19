#include <stdio.h>

#define FILAS 5
#define COLUMNAS 5

int main() {
    int matriz[FILAS][COLUMNAS];
    int i, j, num, encontrado = 0;

    // Ingreso y validación de datos
    printf("Ingrese numeros enteros entre 1 y 99 para una matriz 5x5:\n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            do {
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                if (matriz[i][j] < 1 || matriz[i][j] > 99) {
                    printf("Valor invalido. Ingrese un numero entre 1 y 99.\n");
                }
            } while (matriz[i][j] < 1 || matriz[i][j] > 99);
        }
    }

    // Ingreso del numero a buscar
    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d", &num);

    // Búsqueda en la matriz
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == num) {
                encontrado = 1;
                printf("\nNumero %d encontrado en la posicion [%d][%d]\n", num, i, j);
                printf("Direccion de memoria: %p\n", &matriz[i][j]);
            }
        }
    }

    if (!encontrado) {
        printf("\nEl numero %d no fue encontrado en la matriz.\n", num);
    }

    return 0;
}
