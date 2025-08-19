#include <stdio.h>
#include <string.h>

int main ()
{
    char Origen [] = "Programacion en C";
    char Destino [25];

    strcpy (Destino, Origen);

    printf ("Destino: %s\n", Destino);
}