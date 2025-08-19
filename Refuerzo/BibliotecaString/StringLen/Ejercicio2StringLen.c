//Contar y mostrar si la frase ingresada es corta, mediana o larga

#include <stdio.h>
#include <string.h>
int main()
{
    char Frase [132];
    
    printf ("Ingrese una frase segun la clasifiacion sera corta, mediana y larga\n");
    fgets(Frase, sizeof(Frase),stdin);
    Frase[strcspn(Frase, "\n")] = '\0';
    
    if ((strlen(Frase) < 10)){
        printf ("Su frase es catalogada como 'Frase Corta' con %i", strlen(Frase));
    }else if(strlen(Frase) <= 30){
        printf ("Su frase es catalogada como 'Frase mediana' con %i", strlen(Frase));
    }else{
        printf ("Su frase es catalogada como 'Frase Larga' con %i", strlen(Frase));
    }
    return 0;
}