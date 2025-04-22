#include <stdio.h>
//Comentrar cada funcion
int main (){

    FuncionMate();
    return 0;
}

//Ceil es la funcion que redondea al entero mayor mas cercaco
void FuncionMate (){
    float x, cambio = 0;
    printf ("Escribe un numero: ");
    scanf ("%f", &x);

    cambio = ceil (x);
    printf ("%.2f\n", cambio);
}


//Fabs es la funcion que devuelve el valor absoluto de un numero
void FuncionMate (){
    float x, cambio = 0;
    printf ("Escribe un numero: ");
    scanf ("%f", &x);

    cambio = fabs (x);
    printf ("%.2f\n", cambio);
}

//Floor es la funcion que redondea al entero menor mas cercano
void FuncionMate (){
    float x, cambio = 0;
    printf ("Escribe un numero: ");
    scanf ("%f", &x);

    cambio = floor (x);
    printf ("%.2f\n", cambio);
}


//sqrt es la funcion que devuelve la raiz cuadrada de un numero
void FuncionMate (){
    float x, cambio = 0;
    printf ("Escribe un numero: ");
    scanf ("%f", &x);

    cambio = sqrt (x);
    printf ("%.2f\n", cambio);
}

//fmod Calcula el resto de la división de x/y
void FuncionMate (){
    float x, y, cambio = 0;
    printf ("Escribe dos numero: ");
    scanf ("%f %f", &x, &y);

    cambio = fmod (x,y);
    printf ("%.2f\n", cambio);
}

//Pow calcula la potencia de x^y
void FuncionMate (){
    float x, y, cambio = 0;
    printf ("Escribe dos numero: ");
    scanf ("%f %f", &x, &y);

    cambio = pow (x,y);
    printf ("%.2f\n", cambio);
}
