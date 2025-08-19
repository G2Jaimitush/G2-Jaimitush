#include <stdio.h>

int main (){

    int filas, columnas, fila, suma = 0;
    
    printf("Ingrese filas y columnas: ");
    scanf("%d%d", &filas, &columnas);
    int matriz[filas][columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    printf("Ingrese la fila a sumar: ");
    scanf("%d", &fila);
    for (int j = 0; j < columnas; j++)
        suma += matriz[fila][j];

    printf("Suma de fila %d: %d\n", fila, suma);

    return 0;
}