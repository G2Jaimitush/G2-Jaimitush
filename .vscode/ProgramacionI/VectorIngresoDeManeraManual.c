#include <stdio.h>

int main()
{
    int vector [5]; // = {7,13,69,8,11}; // Inicializacion del vector
    int suma = 0,i;
    
    //Declarar los espacios del vector
    for (i = 0; i < 5; i++){
        printf ("Al vector [%d] sea igual = ",i);
        scanf ("%d",&vector [i]);   
        printf ("\n");
    }
    
    
    //Desplegar el contenido
    for (int i = 0; i < 5; i++){
        printf ("El vector en la posicion [%d] es = %d\n", i ,vector[i]);
    }
    
    
    // Sumar los elementos del vector
    
    for (int i = 0; i < 5; i++){
        suma += vector [i];
    }
    printf ("La suma de los elementos del vector es: %d\n",suma);
    
    return 0;
}
