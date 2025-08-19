#include <stdio.h>
int main (){
    int num,i,suma = 0,original;
    printf ("Ingrese un numero: ");
    scanf ("%d",&num);
    
    while (num <= 0){
        printf ("Ingrese un numero positivo: ");
        scanf ("%d",&num);
    }
    original = num;

    while (num > 0){
        i = num % 10; // Obtener el último dígito
        suma += i; // Sumar el dígito a la suma total
        num /= 10; // Eliminar el último dígito del número
    }

    printf ("La suma de %d sus numero es de: %d",num,suma);
}