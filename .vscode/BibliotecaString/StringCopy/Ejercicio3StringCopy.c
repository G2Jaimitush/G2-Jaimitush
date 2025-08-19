//Tienes una lista de nombres y quieres copiarlos a otro arreglo.

#include <stdio.h>
#include <string.h>

int main (){

    char Nombres [3][25] = {"Ana", "Pedro", "Maria"};
    char Copia [3][25];

    for (int i = 0; i < 3; i++){
        strcpy (Copia[i], Nombres [i]);
        printf ("Nombre Guardado: %s\n", Copia);
    }
    
    for (int i = 0; i < 3; i++){
        printf ("Nombres Copiados: %s\n", Copia[i]);
    }
}