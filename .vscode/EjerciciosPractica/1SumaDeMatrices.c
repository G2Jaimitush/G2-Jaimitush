#include <stdio.h>

int main () {

    int i, j;
    int Filas1, Columnas1;
    int Filas2, Columnas2;

    VERIFICACION:
    // Se pide al usuario que ingrese las dimensiones de la matriz 1
    printf("Ingrese el numero de filas de la matriz 1: ");
    scanf("%d", &Filas1);
    printf("Ingrese el numero de columnas de la matriz 1: ");
    scanf("%d", &Columnas1);

    // Se pide al usuario que ingrese las dimensiones de la matriz 2
    printf("Ingrese el numero de filas de la matriz 2: ");
    scanf("%d", &Filas2);
    printf("Ingrese el numero de columnas de la matriz 1: ");
    scanf("%d", &Columnas2);

    // Se verifica que las dimensiones de ambas matrices sean iguales
    if (Filas1 != Filas2 || Columnas1 != Columnas2) {
        printf("\nERROR: Las matrices deben tener la misma cantidad de filas y columnas para poder sumarse.\n");
        goto VERIFICACION;
    }

    int matriz1[Filas1][Columnas1];
    int matriz2[Filas2][Columnas2];
    int SumaTotal = 0;

    //Se pide al usuario que ingrese los elementos de la matriz 1
    printf ("\tIngrese los elementos de la matriz 1:\n");
    for (i = 0; i < Filas1; i++){
        for (j = 0; j < Columnas1; j++){
            printf("Matriz 1 [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    //Se pide al usuario que ingrese los elementos de la matriz 2
    printf ("\tIngrese los elementos de la matriz 2:\n");
    for (i = 0; i < Filas2; i++){
        for (j = 0; j < Columnas2; j++){
            printf("Matriz 2 [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    //Despliega la matriz 1
    printf ("\tPrimera Matriz %d x %d:\n", Filas1, Columnas1);
    for (i = 0; i <Filas1; i++){
        for (j = 0; j < Columnas1; j++){
            printf ("En la posicion [%d] [%d] es = %d \n",i,j, matriz1[i][j]);
        }
    }

    //Despliegue de la Matriz 1 TOTAL
    printf ("\tPrimera Matriz %d x %d en forma de matriz:\n", Filas1, Columnas1);
    for (i = 0; i <Filas1; i++){
        for (j = 0; j < Columnas1; j++){
            printf ("%d ",matriz1[i][j]);
        }
        printf ("\n");
    }    

    //Despliega la matriz 2
    printf ("\tSegunda Matriz %d x %d:\n", Filas2, Columnas2);
    for (i = 0; i <Filas2; i++){
        for (j = 0; j < Columnas2; j++){
            printf ("En la posicion [%d] [%d] es = %d \n",i,j, matriz2[i][j]);
        }
    }


    //Despliegue de la Matriz 2 TOTAL
    printf ("\tPrimera Matriz %d x %d en forma de matriz:\n", Filas2, Columnas2);
    for (i = 0; i <Filas2; i++){
        for (j = 0; j < Columnas2; j++){
            printf ("%d ",matriz2[i][j]);
        }
        printf ("\n");
    }    

    //Suma de las matrices
    for (i = 0; i <Filas2; i++){
        for (j = 0; j < Columnas2; j++){
            SumaTotal += matriz1[i][j] + matriz2[i][j];
        }
    }

    //Despliega la suma total de las matrices
    printf ("\tLa suma total de ambas matrices es: %d \n",SumaTotal);

    //Suma de las matrices forma de matriz
    printf ("\tSuma de las matrices %d x %d:\n", Filas2, Columnas2);
    for (i = 0; i <Filas2; i++){
        for (j = 0; j < Columnas2; j++){
            printf ("%d ",matriz1[i][j] + matriz2[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
