#include <stdio.h>

int main (){

    int filas, columnas, col, suma = 0;

    printf("Ingrese filas y columnas: ");
    scanf("%d%d", &filas, &columnas);
    int matriz[filas][columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    printf("Ingrese la columna a sumar: ");
    scanf("%d", &col);
    for (int i = 0; i < filas; i++)
        suma += matriz[i][col];

    printf("Suma de columna %d: %d\n", col, suma);

    return 0;
}