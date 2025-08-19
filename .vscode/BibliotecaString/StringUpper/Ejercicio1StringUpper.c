//Comparar dos frases ignorando mayúsculas/minúsculas

#include <stdio.h>
#include <string.h>
int main()
{
    char frase1[64];
    char frase2[64];
    
    printf ("Ingrese la primera frase a comparar: ");
    fgets(frase1,sizeof(frase1),stdin);
    frase1[strcspn(frase1, "\n")]='\0';
    
    
    printf ("Ingrese la segunda frase a comparar: ");
    fgets(frase2,sizeof(frase2),stdin);
    frase2[strcspn(frase2, "\n")]='\0';


    if((strcmp (strupr(frase1),strupr(frase2)) ) ==0){
        printf ("Las frases coinciden");
    }else{
        printf ("Las frases no coinciden");
    }
    return 0;
}