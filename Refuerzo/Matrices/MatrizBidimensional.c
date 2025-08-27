#include <stdio.h>

int main () {

    int matriz [3][3];
    
    //Ingreso de Datos
        //Ingreso primero a las filas
    for (int i = 0; i < 3; i++){
            //Ingreso despues a las columnas
        for (int j = 0; j < 3; j++){
            printf ("Ingrese de datos de la matriz en la posicion [%d] [%d]: ", i,j); 
            scanf ("%d",&matriz[i][j]);        
        }
    }
    
    //Imprimir matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("%d", matriz[i][j]); 
        }
        printf ("\n");
    }
    return 0;

}