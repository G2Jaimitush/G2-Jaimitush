#include <stdio.h>

int main (){

    int i;
    //Dimenciones de los vectores
    printf ("Ingrese la dimencion del vector: ");
    scanf ("%d", &i);

    int Vector1[i], Vector2 [i];
    
    //Ingreso de los elementos del primer vector
    printf ("\tIngrese los elementos del primer vector: \n");
    for (int j = 0; j < i; j++){
        printf ("Ingrese el elemento del primer vector [%d]: ", j);
        scanf ("%d", &Vector1[j]);
    }

    //Ingreso de los elementos del segundo vector
    printf ("\tIngrese los elementos del segundo vector: \n");
    for (int j = 0; j < i; j++){
        printf ("Ingrese el elemento del segundo vector [%d]: ", j);
        scanf ("%d", &Vector2[j]);
    }

    //Despliegue de los elementos del primer vector
    printf ("\tElementos del primer vector: \n");
    for (int j = 0; j < i; j++){
        printf ("El elemento del primer vector es [%d] es : %d\n", j, Vector1[j]);
    }

    //Despliegue de los elementos del segundo vector
    printf ("\tElementos del segundo vector: \n");
    for (int j = 0; j < i; j++){
        printf ("El elemento del segundo vector es [%d] es : %d\n", j, Vector1[j]);
    }

    //Interseccion de los vectores posicion por posicion
    printf ("\tInterseccion de los vectores: \n");
    for (int j = 0; j < i; j++){
        if (Vector1[j] == Vector2[j]) {
           printf ("El elemento [%d] es igual en ambos vectores: %d\n", j, Vector1[j]); 
        }
    }
    return 0;
}