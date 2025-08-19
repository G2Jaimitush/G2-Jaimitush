//Pide al usuario que ingrese 5 nombres (máximo 30 caracteres cada uno).
//Guarda cada nombre en un arreglo de cadenas.
//Luego copia todos los nombres a otro arreglo usando strcpy y finalmente muestra la lista de nombres copiados.

#include <stdio.h>
#include <string.h>

int main (){

    char NombresIngresar [5][25];
    char Copia [5][25];
    
    for (int i = 0; i < 5; i++){
        printf ("Ingrese el nombre de la persona %d:",i + 1);
        fgets (NombresIngresar[i], sizeof(NombresIngresar[i]),stdin);
    }
    
    for (int i = 0; i < 5; i++){
        strcpy (Copia[i], NombresIngresar[i]);
        printf ("Nombre Copiado: %s\n",Copia[i]);
    }
}
