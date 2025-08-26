//Conversion de Temperatura

#include <stdio.h>
double GradosFahrenheit (float a);
double GradosKelvin (float a);

int main()
{
    float grados, resultado;
    int opc;
    
    
    printf ("Ingrese como desea realizar la convercion de grados Fahrenheit o Kelvin\n");
    printf ("Presion (1) para ingresar grados Fahrenheit\n");
    printf ("Presione (2) para ingresar grados Kelvin\n"); scanf ("%d",&opc);
        
    switch (opc){
        case 1:
            printf ("Ingrese los grados Fahrenheit: "); scanf ("%f",&grados);
            resultado = GradosFahrenheit(grados);
            printf ("El cambio de Grados Fahrenheit a Kelvin es: %f",resultado);
        break;
            
        case 2:
            printf ("Ingrese los grados Kelvin: "); scanf ("%f", &grados);
            resultado = GradosKelvin (grados);
            printf ("El cambio de grados Kelvin a Fahrenheit es: %f",resultado);
        break;
        
        default:
            printf ("Opcion Invalida\n");
        break;
    }
    
    
    return 0;
}

double GradosFahrenheit (float a){
    
    float CambioDeGradosAKelvin;
    
    CambioDeGradosAKelvin = ((a - 32) * 5/9 + 273.15);
    return CambioDeGradosAKelvin;
}

double GradosKelvin (float a){
        
    float CambioDeGradosAFahrenheit;
    CambioDeGradosAFahrenheit = ((a - 273.15) * 9/5 + 32);
    
    return CambioDeGradosAFahrenheit;
}


