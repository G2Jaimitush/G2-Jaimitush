#include <stdio.h>

int main (){
    int i,diferencia = 0;

    //Declaracion de la dimension de los vectores
    printf ("Ingrese la dimension de los vectores: ");
    scanf ("%d",&i);

    //Declaracion de los Vectores
    int Vector1 [i], Vector2 [i];


    //Ingrese los valores del primer vector
    printf ("\tIngrese los valores del primer vector\n");
    for (int j = 0; j < i; j++){
        printf ("Ingrese el valor del primer vector en la poscion [%d] = ",j);
        scanf ("%d",&Vector1[j]);
    }


    //Ingrese los valores del segundo vector
    printf ("\tIngrese los valores del segundo vector\n");
    for (int j = 0; j < i; j++){
        printf ("Ingrese el valor del segundo vector en la poscion [%d] = ",j);
        scanf ("%d",&Vector2[j]);
    }


    //Despligue del contenido del primer Vector
    printf ("\tPrimer Vector\n");
    for (int j = 0; j < i; j++){
        printf ("Primer Vector en la posicion [%d] es de = %d\n", j, Vector1 [j]);
    }


    //Despligue del contenido del segundo Vector
    printf ("\tSegundo Vector\n");
    for (int j = 0; j < i; j++){
        printf ("Segundo Vector en la posicion [%d] es de = %d\n", j, Vector2 [j]);
    }

    //Diferencia de los Vectores
    printf ("\tDiferencia de los vectores\n");
    for (int j = 0; j < i; j++){
        diferencia = Vector1[j] - Vector2 [j];
        printf ("La diferencia de los vectores en la posicion [%d] es de: %d\n", j, diferencia);
    }
    return 0;
}