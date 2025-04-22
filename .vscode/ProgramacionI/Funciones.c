#include <stdio.h>

int incrementar(int num);

int main (){

    int a= 5, num;
    printf ("Dentro de la funcion: %d\n", a);
    /*num = incrementar(a);
    printf ("Despues de la funcion: %d\n", num);*/
    printf ("Despues de la funcion: %d\n", incrementar (a)); //Es lo mismo que la anterior, pero se hace en una sola linea
    return 0;
}


int incrementar(int num){
    /*num = num + 8;*/
    return num + 8; // Es lo mismo que la anterior, pero se hace en una sola linea
}

