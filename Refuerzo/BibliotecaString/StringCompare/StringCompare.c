#include <stdio.h>
#include <string.h>
int main()
{
    char Clave [] = "Mava2006";
    char Ingreso [30];
    int Intentos = 3;
    
    do{
        printf ("Ingrese su clave de seguridad: ");
        fflush (stdin);
        scanf ("%s",Ingreso);
        if (strcmp(Clave, Ingreso)==0){
            printf ("Acceso correcto");
            break;
        }else{
            Intentos--;
            printf("Acceso Incorrecto, te quedan %d intentos restantes\n",Intentos);
        }
    }while(Intentos>0);
    
    return 0;
}

