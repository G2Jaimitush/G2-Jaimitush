#include <stdio.h>

int main (){

    int filas, columnas, max, min;
    
    printf("Ingrese filas y columnas: ");
    scanf("%d%d", &filas, &columnas);
    int matriz[filas][columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    max = min = matriz[0][0];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > max) max = matriz[i][j];
            if (matriz[i][j] < min) min = matriz[i][j];
        }

    printf("Máximo: %d, Mínimo: %d\n", max, min);

    return 0;
}