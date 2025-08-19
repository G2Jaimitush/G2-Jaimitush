#include <stdio.h>
#include "Matrices.h"


// Función principal
int main() {
    int matriz[FILAS][COLUMNAS];
    int numero;

    llenar_matriz(matriz);

    printf("\nIngrese el numero a buscar: ");
    scanf("%d", &numero);

    buscar_numero(matriz, numero);

    return 0;
}
