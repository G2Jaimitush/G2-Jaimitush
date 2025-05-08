#include <stdio.h>
#include "Funciones.h"

// Declaraciones de funciones
int Sumar(int *p1, int *p2);
int Restar(int *p1, int *p2);
int Dividir(int *p1, int *p2);
int Multiplicar(int *p1, int *p2);

int main() {
    int num1, num2;
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    int *p1 = &num1;
    int *p2 = &num2;

    printf("Suma: %d\n", Sumar(p1, p2));
    printf("Resta: %d\n", Restar(p1, p2));
    printf("Multiplicacion: %d\n", Multiplicar(p1, p2));
    printf("Division: %d\n", Dividir(p1, p2)); 
    

    return 0;
}