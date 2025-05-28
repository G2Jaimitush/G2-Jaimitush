#define MATRIZ_UTILS_H
#define MATRIZ_UTILS_H

#define FILAS 5
#define COLUMNAS 5

void llenar_matriz(int matriz[FILAS][COLUMNAS]);
void buscar_numero(int matriz[FILAS][COLUMNAS], int numero);

void llenar_matriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;
    printf("Ingrese numeros entre 1 y 99 para la matriz 5x5:\n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            do {
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                if (matriz[i][j] < 1 || matriz[i][j] > 99) {
                    printf("Valor invalido. Intente de nuevo.\n");
                }
            } while (matriz[i][j] < 1 || matriz[i][j] > 99);
        }
    }
}


void buscar_numero(int matriz[FILAS][COLUMNAS], int numero) {
    int i, j, encontrado = 0;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == numero) {
                encontrado = 1;
                printf("\nNumero %d encontrado en [%d][%d]\n", numero, i, j);
                printf("Direccion de memoria: %p\n", &matriz[i][j]);
            }
        }
    }
    if (!encontrado) {
        printf("\nEl numero %d no fue encontrado en la matriz.\n", numero);
    }
}

