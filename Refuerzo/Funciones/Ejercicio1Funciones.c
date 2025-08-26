#include <stdio.h>

float Sumar (float a, float b);
float Restar (float a, float b);
float Dividir (float a, float b);
float Multiplicar (float a, float b);
int main()
{
    float num1, num2, resultado;
    int opc;
    printf ("Bienvenido al menu de opciones de la calculadora\n");
    printf ("Ingrese el primer numero: ");scanf ("%f",&num1);
    printf ("Ingrese el segundo numero: "); scanf ("%f",&num2);
    do{
        resultado = 0;
        printf ("1. Sumar\n");
        printf ("2. Restar\n");
        printf ("3. Multiplicar\n");
        printf ("4. Dividir\n");
        printf ("5. Salir Del Programa\n");
        printf ("SELECCION UNA OPCION: "); scanf ("%d",&opc);
        
        switch(opc){
            case 1:
                resultado = Sumar (num1, num2);
                printf ("La suma de: %.2f + %.2f = %.2f\n", num1,num2,resultado);
            break;
            
            case 2:
                resultado = Restar(num1,num2);
                printf ("La resta de: %.2f - %.2f = %.2f\n", num1,num2,resultado);
            break;
            
            case 3:
                resultado = Multiplicar (num1,num2);
                printf ("La multiplicacion de: %.2f x %.2f = %.2f\n", num1,num2,resultado);
            break;
            
            case 4:
                if (num2 == 0){
                    printf ("No existe la division para cero\n");
                    break;
                }else{
                    
                    resultado = Dividir (num1, num2);
                    printf ("La division de: %.2f / %.2f = %.2f", num1,num2,resultado);
                    break;
                }
            default:
                printf ("Opcion INVALIDA\n");
            break;
        }
    }while (!(opc == 5));

    return 0;
}

float Sumar (float a, float b){
    return a + b;
}

float Restar (float a, float b){
    return a - b;
}

float Multiplicar (float a, float b){
    return a * b;
}

float Dividir (float a, float b){
    return a / b;
}

