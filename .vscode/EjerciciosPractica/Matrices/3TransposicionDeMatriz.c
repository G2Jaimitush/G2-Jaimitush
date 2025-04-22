#include <stdio.h>

int main (){

    int filas, columnas;
    printf("Ingrese numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];
    int transpuesta[columnas][filas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            transpuesta[j][i] = matriz[i][j];
        }

    printf("Matriz transpuesta:\n");
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            printf("%d ", transpuesta[i][j]);
        }
        printf("\n");
    }
    return 0;
}