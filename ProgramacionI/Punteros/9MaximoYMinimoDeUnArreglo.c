#include <stdio.h>

void encontrarMinMax(int arreglo[], int tamaño, int *min, int *max) {
    *min = *max = arreglo[0];

    for (int i = 1; i < tamaño; i++) {
        if (arreglo[i] < *min)
            *min = arreglo[i];
        if (arreglo[i] > *max)
            *max = arreglo[i];
    }
}

int main() {
    int numeros[100], n, minimo, maximo;

    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    printf("Ingrese %d numeros enteros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    encontrarMinMax(numeros, n, &minimo, &maximo);

    printf("El valor minimo es: %d\n", minimo);
    printf("El valor maximo es: %d\n", maximo);

    return 0;
}
