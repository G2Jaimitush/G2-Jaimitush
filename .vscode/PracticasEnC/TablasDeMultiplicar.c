#include <stdio.h>
int main (){
    int num,i;
    i = 0;
    printf ("===Tabla de Multiplicacion===\n");
    printf ("Escribe el numero del cual deseas saber la tabla de multiplicar\n");
    scanf ("%i",&num);
    printf ("\tLa tabla de multiplicar del %i es: \n",num);
    while (i <=13){
        printf ("%i x %i = %i\n",num,i,num*i);
        i++;
    }

    return 0;
}