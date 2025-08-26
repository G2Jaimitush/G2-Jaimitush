#include <stdio.h>
#include <math.h>
// Prototipo con parámetros
int sumarNumeros(int a, int b);

int main() {
    int num1, num2, resultado;
    
    printf("Ingrese el primer numero para sumar: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo numero para sumar: ");
    scanf("%d", &num2);
    
    resultado = sumarNumeros(num1, num2); // llamada con argumentos
    
    printf("La suma es: %d\n", resultado);
    
    return 0;
}

// Definición de la función con parámetros
int sumarNumeros(int a, int b) {
    return a + b;
}

