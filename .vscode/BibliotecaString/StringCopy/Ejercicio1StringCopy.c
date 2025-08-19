// Pide al usuario que ingrese su nombre y cópialo en otra variable para mostrarlo dos veces.

#include <stdio.h>
#include <string.h>

int main() {

    char Nombre [25];
    char Destino [25];

    printf ("Ingrese su nombre: ");
    fgets(Nombre, sizeof(Nombre), stdin);

    strcpy (Destino, Nombre);

    printf ("Variable Origen: %s", Nombre);
    printf ("Variable Destino: %s", Destino);

}
