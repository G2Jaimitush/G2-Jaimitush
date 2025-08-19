#include <stdio.h>

int main (){
    int num, i;
    printf ("Ingrese un numero: \n");
    scanf ("%d", &num);

    while (num <= 0){
        printf ("El numero es negativo o cero, ingrese un numero positivo: \n");
        scanf ("%d", &num);
    }

    if (num % 2 == 0){
        printf ("El numero %d es par\n", num);
    }else{
        printf ("El numero %d es impar\n", num);
    }
    printf ("Los numeros pares desde 1 hasta %d son: \n", num);
    for (i = 1; i <= num; i++){
        if (i % 2 == 0){
            printf ("%d ", i);
        }
    }
    printf ("\n");


}