#include <stdio.h>
int main (){
    //Inicializacion de variables
    int i,suma = 0,numMaximo = -1,numMinimo = 9999999;

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

    //Maximo elemento del vector
    for (int j = 0; j < i; j++){ 
        if (vector [j] > numMaximo){
            numMaximo = vector [j];
        }       
    }

    //Minimo elemento del vector
    for (int j = 0; j < i; j++){ 
        if (vector [j] < numMinimo){
            numMinimo = vector [j];
        }       
    }
    printf ("El maximo elemento del vector es = %d\n", numMaximo);
    printf ("El minimo elemento del vector es = %d\n", numMinimo);    
    
    return 0;

}