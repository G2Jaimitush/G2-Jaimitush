//Pide al usuario ingresar su nombre y su apellido (máximo 30 caracteres cada uno).
//Concatena ambos con un espacio entre medio y muestra el nombre completo.

#include <stdio.h>
#include <string.h>
int main()
{
    char Nombre [50];
    char Apellido [50];
    char Final [100] = "";
    
    printf ("Ingrese su nombre: ");
    fgets(Nombre, sizeof(Nombre),stdin);
    Nombre[strcspn(Nombre, "\n")] = '\0'; // Quita el salto de línea al final de la cadena

    
    printf ("Ingrese su Apellido: ");
    fgets(Apellido, sizeof(Apellido),stdin);
    Apellido[strcspn(Apellido, "\n")] = '\0'; // Quita el salto de línea al final de la cadena

    
    strcat (Final, Nombre);
    strcat (Final, " ");
    strcat (Final, Apellido);
    
    printf ("%s", Final);
    return 0;
}