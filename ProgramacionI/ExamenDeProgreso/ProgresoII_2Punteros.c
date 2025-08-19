#include <stdio.h>

#define FILAS 5
#define COLUMNAS 5

int main() {
    int matriz[FILAS][COLUMNAS];
    int *ptr = &matriz[0][0];  // Puntero al primer elemento de la matriz
    int num, encontrado = 0;

    // Ingreso y validación de datos usando punteros
    printf("Ingrese numeros enteros entre 1 y 99 para una matriz 5x5:\n");
    for (int i = 0; i < FILAS * COLUMNAS; i++) {
        do {
            printf("Elemento [%d][%d]: ", i / COLUMNAS, i % COLUMNAS);
            scanf("%d", ptr + i);
            if (*(ptr + i) < 1 || *(ptr + i) > 99) {
                printf("Valor invalido. Ingrese un numero entre 1 y 99.\n");
            }
        } while (*(ptr + i) < 1 || *(ptr + i) > 99);
    }

    // Ingreso del número a buscar
    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d", &num);

    // Búsqueda del número usando punteros
    for (int i = 0; i < FILAS * COLUMNAS; i++) {
        if (*(ptr + i) == num) {
            encontrado = 1;
            int fila = i / COLUMNAS;
            int columna = i % COLUMNAS;
            printf("\nNumero %d encontrado en la posicion [%d][%d]\n", num, fila, columna);
            printf("Direccion de memoria: %p\n", (ptr + i));
        }
    }

    if (!encontrado) {
        printf("\nEl numero %d no fue encontrado en la matriz.\n", num);
    }

    return 0;
}
