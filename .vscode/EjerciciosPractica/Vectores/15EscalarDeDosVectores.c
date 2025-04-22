#include <stdio.h>

int main()
{
    //Declaracion de las variables
    int i,escalar = 0, total = 0;
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
    
    //Escalar de los Vectores
    printf ("\tEscalar de los vectores\n");
    for (int j = 0; j < i; j++){
        escalar = Vector1[j] * Vector2 [j];
        total += escalar;
    }
    printf ("El escalar de los dos vectores es de: %d",total);
    return 0;
}