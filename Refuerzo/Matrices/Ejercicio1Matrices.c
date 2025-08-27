//Contar números pares e impares

#include <stdio.h>

int main() {

    int Matriz [4][4];
    int ContadorPares = 0, ContadorImpares = 0;
    
    //Ingrese de datos
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf ("Ingrese los datos de la matriz 4 x 4 en la posicion [%d] [%d] = ", i,j); 
            scanf ("%d",&Matriz[i][j]);
        }
    }
    
    //Imprimir la Matriz
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf ("%d ",Matriz[i][j]);
        }
        printf ("\n");
    }
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (Matriz[i][j] % 2 == 0){
                ContadorPares++;
            }else{
                ContadorImpares++;
            }
        }
    }
    
    printf ("La cantidad de numeros pares es de: %d\n", ContadorPares);
    printf ("La cantidad de numeros impares es de: %d",ContadorImpares);
    
    return 0; 
}