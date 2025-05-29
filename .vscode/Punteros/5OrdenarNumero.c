#include <stdio.h>

void ordenarDosNumeros(int *a, int *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int x, y;
    printf("Ingrese dos numeros:\n");
    scanf("%d %d", &x, &y);

    ordenarDosNumeros(&x, &y);

    printf("Ordenados de menor a mayor: %d, %d\n", x, y);
    return 0;
}
