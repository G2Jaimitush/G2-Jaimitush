#include <stdio.h>

int main (){

    int num, invertido = 0, original, digito;
    printf ("=== Invertidor de Numeros ===\n");
    printf ("\tIngrese un numero positivo y mayor de un digitos: \n");
    scanf ("%d",&num);

    while (num <= 0 || num < 10){
        printf ("Ingrese un numero positivo y mayor de un digitos: ");
        scanf ("%d",&num);
    }
    original = num;

    for (; num > 0; num /= 10) {
        digito = num % 10;
        invertido = invertido * 10 + digito;
    }

    printf ("El numero invertido seria: %d\n",invertido);

    return 0;
}