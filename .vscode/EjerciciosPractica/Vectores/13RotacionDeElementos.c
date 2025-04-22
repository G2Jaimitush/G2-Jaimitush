#include <stdio.h>

int main() {
    int i;

    // Declaración de la dimension del vector
    printf("Ingrese la dimensio del vector: ");
    scanf("%d", &i);

    // Declaración del Vector original y sus copias
    int Vector1[i], Vector1Der[i], Vector1Izq[i];

    // Ingreso de valores del vector original
    printf("\tIngrese los valores del vector\n");
    for (int j = 0; j < i; j++) {
        printf("Ingrese el valor en la posicion [%d] = ", j);
        scanf("%d", &Vector1[j]);
    }

    // Copiar el vector original para rotaciones
    for (int j = 0; j < i; j++) {
        Vector1Der[j] = Vector1[j];
        Vector1Izq[j] = Vector1[j];
    }

    // Despliegue del Vector original
    printf("\n\tVector Original\n");
    for (int j = 0; j < i; j++) {
        printf("Posicion [%d] = %d\n", j, Vector1[j]);
    }

    // Rotación a la derecha
    int ultimo = Vector1Der[i - 1];
    for (int j = i - 1; j > 0; j--) {
        Vector1Der[j] = Vector1Der[j - 1];
    }
    Vector1Der[0] = ultimo;

    // Mostrar rotación a la derecha
    printf("\n\tVector Rotado a la Derecha\n");
    for (int j = 0; j < i; j++) {
        printf("Posicion [%d] = %d\n", j, Vector1Der[j]);
    }

    // Rotación a la izquierda
    int primero = Vector1Izq[0];
    for (int j = 0; j < i - 1; j++) {
        Vector1Izq[j] = Vector1Izq[j + 1];
    }
    Vector1Izq[i - 1] = primero;

    // Mostrar rotación a la izquierda
    printf("\n\tVector Rotado a la Izquierda\n");
    for (int j = 0; j < i; j++) {
        printf("Posicion [%d] = %d\n", j, Vector1Izq[j]);
    }

    return 0;
}

