#include <stdio.h>
int main (){
    //Inicializacion de variables
    int i,suma = 0,posicion = 0;

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

    //Buscar un elemento en el vector
    do{
        printf ("\tEn que posicion deseas buscar el elemento: ");
        scanf ("%d",&posicion);
        if (posicion < 0 || posicion >= i){
            printf ("\nLa posicion no existe\n");
        }
    }while (posicion >= i || posicion < 0);

    printf ("El elemento en la posicion [%d] es = %d\n", posicion ,vector[posicion]);

    return 0;
}