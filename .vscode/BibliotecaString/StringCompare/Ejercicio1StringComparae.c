//El usuario adivinar una frase fija con 3 intentos

#include <stdio.h>
#include <string.h>
int main()
{
    char Frase [] = "Hola Mundo";
    char Adivina [32];
    int intentosRestantes = 3;
    
    do{
        printf ("Adivina la frase. Pista tipica frase de programacion tienes %d intentos.\n",intentosRestantes);
        fflush (stdin);
        fgets(Adivina,sizeof(Adivina),stdin);
        Adivina[strcspn(Adivina, "\n")]='\0';
        if (strcmp (Frase, Adivina)==0){
            printf ("Frase Correcta. Gracias por jugar");
            break;
        }else{
            intentosRestantes--;
            printf ("Frase Incorrecta. Te quedan %d intentos\n",intentosRestantes);
        }
    }while (intentosRestantes > 0);
    
    return 0;
}