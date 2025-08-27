////Buscar un número en la matriz

#include <stdio.h>

int main() {

    int Matriz [3][5];
    int num, encontrado = 0;
    
    //Ingrese de datos
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf ("Ingrese los datos de la matriz 3 x 5 en la posicion [%d] [%d] = ", i,j); 
            scanf ("%d",&Matriz[i][j]);
        }
    }
    
    //Imprimir la Matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf ("%d ",Matriz[i][j]);
        }
        printf ("\n");
    }
    
    
    //Pedir al usuario un numero a Buscar
    printf ("Escribe un numero para buscar: "); scanf ("%d",&num);
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (Matriz[i][j] == num){
                printf ("Se encontro el numero en la posicion [%d][%d]\n",i,j);
                encontrado = 1;
            }
        }
    }
    
    if (encontrado == 0){
        printf ("No se encontro el numero dentro de la matriz\n");
    }
    
    return 0; 
}