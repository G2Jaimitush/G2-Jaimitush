#include <stdio.h>

int main (){
    int i;
    //Dimencion del vector
    printf ("Ingrese la dimencion del vector: ");
    scanf ("%d", &i);
    int vector[i];

    //Ingreso de los elementos del vector
    for (int j = 0; j < i; j++){
        printf ("Ingrese el elemento del vector [%d]: ", j);
        scanf ("%d", &vector[j]);
    }

    //Despliegue de los elementos del vector
    for (int j = 0; j < i; j++){
        printf ("El elemnto del vector [%d] es: %d\n",j, vector [j]);
    }

    //Eliminacion de duplicados
    for (int j = 0; j < i; j++){
        if (vector[j] != -1){
            for (int k = j + 1; k < i; k++){
                if (vector[j] == vector[k]){
                    vector[k] = -1;
                }
            }
        }
    }

    //Despliegue de los elementos del vector sin duplicados
    printf ("Vector sin dupilicados: \n");
    for (int j = 0; j < i; j++){
        if (vector[j] != -1){
            printf ("El elemnto del vector [%d] es: %d\n",j, vector [j]);
        }
    }

    return 0;
}