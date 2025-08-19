#include <stdio.h>
#include "CalculadoraFunciones.h"
int main() {
    int opcion;
    int num1, num2;

    printf("\tBienvenido\n");
    do {
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Escoge una opcion: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                printf("Escribe dos numeros a sumar: \n");
                scanf("%i %i", &num1, &num2);
                printf("La suma de %i + %i es de: %i\n", num1, num2, sumar(num1, num2));
                break;

            case 2:
                printf("Escribe dos numeros a restar: \n");
                scanf("%i %i", &num1, &num2);
                printf("La resta de %i - %i es de: %i\n", num1, num2, restar(num1, num2));
                break;

            case 3:
                printf("Escribe dos numeros a multiplicar: \n");
                scanf("%i %i", &num1, &num2);
                printf("La multiplicacion de %i * %i es de: %i\n", num1, num2, multiplicacion(num1, num2));
                break;

            case 4:
                printf("Escribe dos numeros a dividir: \n");
                scanf("%i %i", &num1, &num2);
                if (num2 == 0) {
                    printf("No se puede dividir entre 0. Intente con otro numero.\n");
                } else {
                    printf("La division de %i / %i es de: %i\n", num1, num2, dividir(num1, num2));
                }
                break;

            case 5:
                printf("Gracias por usar la calculadora\n");
                break;

            default:
                printf("Opcion no valida. Intentelo nuevamente.\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}

