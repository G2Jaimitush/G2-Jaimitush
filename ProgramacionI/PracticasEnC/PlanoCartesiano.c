#include <stdio.h>
int main (){
    int num1, num2;
    printf ("=== Calcular en que cuadrante es tu la coordenada (x, y) ===\n");
    printf ("Ingrese la coordenada del eje (x):");
    scanf ("%d", &num1);
    printf ("Ingrese la coordenada del eje (y):");
    scanf ("%d", &num2);

    if (num1 > 0 && num2 > 0){
        printf ("La coordenada (%d, %d) se encuentra en el primer cuadrante", num1, num2);
    }else if (num1 > 0 && num2 < 0){
        printf ("La coordenada (%d, %d) se encuentra en el cuarto cuadrante", num1, num2);
    }else if (num1 < 0 && num2 > 0){
        printf ("La coordenada (%d %d se encunetra en el segundo cuadrante", num1, num2);
    }else if (num1 < 0 && num2 < 0){
        printf ("La coordenada (%d, %d) se encuentra en el tercer cuadrante", num1, num2);
    }

    return 0;
}

