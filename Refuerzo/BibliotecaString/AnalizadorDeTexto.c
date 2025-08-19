//Analizador de Texto Interactivo

#include <stdio.h>
#include <string.h>

int main()
{

    char texto [126];
    char copy [126];
    char adicional [126];
    char nuevoTexto [256] = "";
    char comparar [126];
    int opc;
    int opc2;
    int opc3;
    char buscar;
    
    printf ("Ingresa una texto: ");
    fgets(texto,sizeof(texto),stdin);
    texto[strcspn(texto,"\n")]='\0';
    
    strcpy(copy,texto);
    
    do{
        printf ("Bienvenido al menu de opciones\n");
        printf ("1. Contar la cantidad de caracteres o palabras del texto\n");
        printf ("2. Copiar el texto a otra variable\n");
        printf ("3. Concatenar frases adicionales al texto\n");
        printf ("4. Comparar dos textos\n");
        printf ("5. Convertir todo el texto en mayusculas o minusculas\n");
        printf ("6. Invertir texto\n");
        printf ("7. Buscar la ultima aparicion de una palabra\n");
        printf ("8. Salir\n");
        printf ("\tIngrese una opcion: ");
        scanf ("%d",&opc);
        getchar();
        switch (opc){
            case 1: 
                printf ("La cantidad de caracteres del texto: %s.\n \tEs de %d palabras\n", texto, strlen(texto));
            break;
            
            case 2:
                strcpy(copy,texto);
                printf ("El texto se ha copiado exitosamente en otra variable\n");
                printf ("Texto copiado: %c",copy);
            break;
            
            case 3:
                strcat (nuevoTexto, texto);
                printf ("\tTen en cuenta que para unir otro texto, se toma en consideracion de lo ultimo que escribiste\n");
                printf ("Ingresa el nuevo texto: ");
                fgets (adicional, sizeof(adicional),stdin);
                adicional[strcspn(adicional,"\n")]='\0';
                
                strcat (nuevoTexto, " ");
                strcat (nuevoTexto,adicional);
                
                printf ("El nuevo texto es el siguiente: %s\n", nuevoTexto);
            break;
            
            case 4:
                
                
                printf ("Ingrese el texto a comparar con el texto original\n");
                fgets (comparar,sizeof(comparar),stdin);
                comparar[strcspn(comparar,"\n")]='\0';
                
                printf ("Desea comparar el texto tal cual como esta o ignorar todas las mayusculas o minusculas\n");
                printf ("1. Comparar texto original\n");
                printf ("2. Ignorando mayusculas\n");
                scanf ("%d",&opc2);
                
                if (opc2 == 1){
                    if (strcmp (texto, comparar) ==0){
                        printf ("El texto concidice correctamente\n");
                        break;
                    }else{
                        printf ("El texto no coincide\n");
                        break;
                    }
                }else if (opc2 == 2){
                    if (strcmp (strlwr(texto),strlwr(comparar))==0){
                        printf ("El texto coincide correctamente\n");
                    }else{
                        printf ("El texto no coicide\n");
                    }
                }else{
                    printf ("Opcion INVALIDA\n");
                }
            break;

            case 5:
            
                printf ("\t1. Convertir el texto en mayusculas\n");
                printf ("\t2. Convertir el texto en minusculas\n");
                scanf ("%d",&opc3);
                
                if (opc3 == 1){
                    printf ("El nuevo texto en mayusculas es: %c\n", strupr(texto));
                }else if (opc3 == 2){
                    printf ("El nuevo texto en minusculas es: %c\n", strlwr(texto));
                }else{
                    printf ("Opcion INVALIDA\n");
                }
            
            break;
            
            case 6:
                printf ("El texto invertido es: %c", strrev(texto));
            break; 
            
            case 7:
                printf("Busca la ultima aparicion de un caracter: ");
                scanf(" %c", &buscar);
                getchar();

                char *ultima = strrchr(texto, buscar);
                if (ultima != NULL) {
                    int pos = ultima - texto;
                    printf("La ultima aparicion del caracter '%c' es en la posicion: %d\n", buscar, pos);
                } else {
                    printf("El caracter '%c' no se encuentra en el texto.\n", buscar);
                }
            break;

            
            default:
                printf ("Opcion no valida. Intentalo nuevamente\n");
            break;
        }
        
    }while (!(opc == 8));
    
    return 0;
}
