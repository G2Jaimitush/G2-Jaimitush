#include <stdio.h>
int main (){
    //Inicializacion de variables
    int i,suma = 0;

    //Declaracion del tamaño del vector
    printf ("Escribe la dimension del vector: ");
    scanf ("%d",&i);

    int vector [i];

    //Declarar los espacios del vector
    for (int j = 0; j < i; j++){
        printf ("Al vector [%d] sea igual = ",j);
        scanf ("%d",&vector [j]);   
        printf ("\n");
    }

    //Desplegar el contenido
    for (int j =0; j < i; j++){
        printf ("El vector en la posicion [%d] es = %d\n", j ,vector[j]);           
    }

    printf ("--------------------\n");
    printf ("El vector invertido es:\n");
    //Invertir el vector
    for (int j = i - 1; j >= 0; j--){
        printf ("El vector en la posicion [%d] es = %d\n", j ,vector[j]);           
    } 

    return 0;
}