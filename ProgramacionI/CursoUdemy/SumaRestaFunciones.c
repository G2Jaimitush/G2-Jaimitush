#include <stdio.h>

void menu();
void sumar();
void restar ();
void multiplicacion ();
void dividir ();


int main (){
    printf ("\tBienvenido\n");
    menu ();

    return 0;
}

void menu (){
    int opcion;
    do{
        printf ("1. Sumar\n");
        printf ("2. Restar\n");
        printf ("3. Multiplicar\n");
        printf ("4. Dividir\n");
        printf ("5. Salir\n");
        printf ("Escoge una opcion: ");
        scanf ("%i",&opcion);

        switch (opcion){
            case 1: sumar ();
            break;

            case 2 : restar ();
            break;

            case 3: multiplicacion ();
            break;

            case 4: dividir ();
            break;

            case 5:
            printf ("Gracias por usar la calculadora\n");
            break;

            default: 
                printf ("Opcion no valida\n");
                printf ("Intentelo nuevamente\n");
                scanf ("%i",&opcion);
            break;    
        }
        
    }while (opcion != 5);
}


void sumar (){
    float num1, num2, resultado = 0;
    printf ("Escribe dos numeros a sumar\n");
    scanf ("%f %f", &num1, &num2);
    resultado = num1 + num2;
    printf ("La suma de %.2f + %.2f es de: %2.f\n",num1,num2,resultado);
    printf ("Que otra operacion quieres hacer?\n");
}


void restar(){
    float num1, num2, resultado = 0;
    printf("Escribe dos numeros a restar\n");
    scanf("%f %f", &num1, &num2);
    resultado = num1 - num2;
    printf("La resta de %.2f - %.2f es de: %.2f\n", num1, num2, resultado);
    printf("Que otra operacion quieres hacer?\n");
}


void multiplicacion (){
    float num1, num2, resultado = 0;
    printf ("Escribe dos numeros a multiplicar\n");
    scanf ("%f %f", &num1, &num2);
    resultado = num1 * num2;
    printf ("La multiplicacio de %.2f * %.2f es de: %.2f\n",num1,num2,resultado);
    printf ("Que otra operacion quieres hacer?\n");
}



void dividir (){
    float num1, num2, resultado = 0;
    printf ("Escribe dos numeros a dividir\n");
    scanf ("%f %f", &num1, &num2);
    resultado = num1 / num2;
    printf ("La division de %.2f / %.2f es de: %.2f\n",num1,num2,resultado);
    printf ("Que otra operacion quieres hacer?");
}
