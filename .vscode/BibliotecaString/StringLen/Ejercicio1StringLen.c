//Validar longitud mínima y máxima de una contraseña

#include <stdio.h>
#include <string.h>
int main()
{
    char Clave [32];
    
    do{
        
        printf ("Ingrese una clave que tenga como minimo 8 caracteres y como maximo 16 caracteres: ");
        fgets(Clave, sizeof(Clave),stdin);
        Clave[strcspn(Clave, "\n")] = '\0';
        if((strlen(Clave)) < 8 || (strlen(Clave) > 16)){
            printf ("Intentalo nuevamente\n");
        }else{
            printf ("Clave ingresado correctamente");
            break;
        }
    }while((strlen(Clave)) < 8 || (strlen(Clave) > 16));
    return 0;
}