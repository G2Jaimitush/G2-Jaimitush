#include <stdio.h>

// Declaración correcta con parámetros
int Sumar(int n1, int n2);

int main () {
    int a, b, Suma;

    printf("Escribe dos numeros: \n");
    scanf("%i %i", &a, &b);

    Suma = Sumar(a, b);
    printf("La suma es: %d\n", Suma);

    return 0;
}

// Definición de la función Sumar
int Sumar(int n1, int n2) {
    return n1 + n2;
}

