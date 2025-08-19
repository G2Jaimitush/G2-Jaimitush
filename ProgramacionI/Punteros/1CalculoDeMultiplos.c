#include <stdio.h>

void CalcularMultiplo (int num1, int num2, int *resultado){
    if (num2 == 0){
        *resultado = -1;
    }else if (num1 % num2 == 0){
        *resultado = 1;
    }else{
        *resultado = 0;
    }
}

int main()
{
    int num1, num2;
    int *ptr1, *ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    int resultado;
    
    printf ("Ingrese el primer numero: ");
    scanf ("%d",&num1);
    
    printf ("Ingrese el segundo numero: ");
    scanf ("%d",&num2);
    
    CalcularMultiplo (num1,num2,&resultado);
    
    if (resultado == -1) {
        printf("No se puede dividir para 0\n");
    } else if (resultado == 1) {
        printf("El %d es multiplo de %d\n", num1, num2);
    } else {
        printf("El %d no es multiplo de %d\n", num1, num2);
    }
    
    return 0;
}