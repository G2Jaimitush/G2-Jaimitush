#include <stdio.h>

int main (){

    int filas, columnas, escalar;

    printf("Ingrese numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    printf("Ingrese el escalar a multiplicar: ");
    scanf("%d", &escalar);

    printf("Resultado de multiplicar por %d:\\n", escalar);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j] * escalar);
        }
        printf("\\n");
    }

    return 0;
}