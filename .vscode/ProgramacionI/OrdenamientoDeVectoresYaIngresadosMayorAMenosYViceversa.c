#include <stdio.h>

int main() {
    int TAM = 5;
    int vector[] = {45, 65, 21, 43, 54};
    int mayor[5], menor[5];
    int aux;
    aux = 0;
    // Copiar los valores del vector original a los vectores mayor y menor
    for (int i = 0; i < TAM; i++) {
        mayor[i] = vector[i];
        menor[i] = vector[i];
    }

    // Ordenar ascendente (menor a mayor)
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (mayor[j] > mayor[j+1]) {
                aux = mayor[j];
                mayor[j] = mayor[j+1];
                mayor[j+1] = aux;
            }
        }
    }

    // Ordenar descendente (mayor a menor)
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (menor[j] < menor[j+1]) {
                aux = menor[j];
                menor[j] = menor[j+1];
                menor[j+1] = aux;
            }
        }
    }

    // Mostrar vector original
    printf("\nVector original:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vector[i]);
    }

    // Mostrar vector en orden ascendente
    printf("\n\nVector ordenado de menor a mayor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", mayor[i]);
    }

    // Mostrar vector en orden descendente
    printf("\n\nVector ordenado de mayor a menor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", menor[i]);
    }

    printf("\n");
    return 0;
}

