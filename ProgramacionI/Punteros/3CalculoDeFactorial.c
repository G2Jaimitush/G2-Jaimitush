#include <stdio.h>

// Función que calcula el factorial usando puntero
void calcularFactorial(int num, int *resultado) {
    *resultado = 1; // inicializar el valor en 1

    for (int i = 1; i <= num; i++) {
        *resultado *= i; // multiplicación acumulada usando puntero
    }
}

int main() {
    int num, factorial;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    calcularFactorial(num, &factorial); // pasamos la dirección de factorial

    printf("El factorial de %d es: %d\n", num, factorial);

    return 0;
}
