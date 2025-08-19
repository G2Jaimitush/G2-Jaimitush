//Validar si una palabra es igual a una palabra secreta (ignorando mayúsculas/minúsculas)

#include <stdio.h>
#include <string.h>

int main() {

    char PalabraSecreta [] = "Ecuador";
    char PalabraIngresada [30];
    char Destino [30];
    
    printf ("Ingrese una palabra: ");
    fgets (PalabraIngresada, sizeof(PalabraIngresada),stdin);
    PalabraIngresada[strcspn(PalabraIngresada, "\n")] = '\0';
    
    strcpy (Destino, PalabraIngresada);
    
    if(strcmp(strlwr(Destino),strlwr(PalabraSecreta)) == 0){
        printf ("Palabra Correcta");
    }else{
        printf ("Palabra Incorrecta");
    }
    
    return 0;    

}