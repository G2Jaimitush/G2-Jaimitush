#include <stdio.h>

int main (){

    int matriz[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    int determinante = matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
    printf("Determinante = %d\n", determinante);

    return 0;
}