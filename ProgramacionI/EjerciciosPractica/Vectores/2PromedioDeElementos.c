#include <stdio.h>
int main (){
    //Inicializacion de variables
    int i,suma = 0,promedio = 0;

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

    //Promedio de los elementos del vector
    for (int j = 0; j < i; j++){         
        suma += vector [j];
    }
    
    promedio = suma / i;
    printf ("El promedio de los elementos del vector es de: %d\n",promedio);
    
    return 0;

}