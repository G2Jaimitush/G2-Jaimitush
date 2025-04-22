#include <stdio.h>

int main (){
    int i,contador = 0;

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

// Calcular frecuencia de aparición de elementos del Vector1 en Vector2
    printf("\nFrecuencia de elementos del Primer Vector en el Segundo Vector:\n");
    for (int j = 0; j < i; j++) {
        contador = 0; // Reiniciar contador para cada elemento de Vector1
        for (int k = 0; k < i; k++) {
            if (Vector1[j] == Vector2[k]) {
                contador++;
            }
        }
    printf("El valor %d del Primer Vector aparece %d veces en el Segundo Vector.\n", Vector1[j], contador);
}
    return 0;
}
