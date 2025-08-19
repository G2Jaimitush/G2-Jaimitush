#include <stdio.h>
int main() {
    int TAM = 5;
    int vector[5], mayor[5], menor[5];
    int aux;
    // Llenar el vector
    printf("Ingresa %d valores para el vector:\n", TAM);
    for (int i = 0; i < TAM; i++) {
        printf("Vector[%d] = ", i);
        scanf("%d", &vector[i]);
        mayor[i] = vector[i];   // Copia para ordenar ascendente
        menor[i] = vector[i];  // Copia para ordenar descendente
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
    // Mostrar original
    printf("\nVector original:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vector[i]);
    }
    // Mostrar ascendente
    printf("\n\nVector ordenado de menor a mayor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", mayor[i]);
    }
    // Mostrar descendente
    printf("\n\nVector ordenado de mayor a menor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", menor[i]);
    }
    printf("\n");
    return 0;
}
