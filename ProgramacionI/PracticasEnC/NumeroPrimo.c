#include <stdio.h>

int main (){
    int num,esPrimo = 1, i;

    printf ("=== Verifica si tu numero es Primo ===\n");
    printf ("Ingrese un numero: ");     
    scanf ("%d",&num);

    while (num <= 1){
        printf ("Ingrese un numero positivo: ");
        scanf ("%d",&num);
    }

    for (i = 2; i < num/2; i++){
        if (num % i == 0){
            esPrimo = 0;
        }
    }

    if (esPrimo == 0){
        printf ("%d No es primo\n",num);
    }else{
        printf ("%d Es primo\n",num);
    }
    return 0;
}

