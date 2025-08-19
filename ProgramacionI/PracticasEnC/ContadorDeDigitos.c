#include <stdio.h>
int main (){

    int numero, contador = 0;
    printf ("Ingrese un numero: \n");
    scanf ("%d", &numero);

    if (numero < 0){
        numero = -numero; // Convertir a positivo
    }

    while (numero > 0){
        numero = numero / 10; // Eliminar el último dígito
        contador++; // Incrementar el contador
    }
    printf ("\nEl numero de digitos es: %d\n", contador);

    return 0;
}