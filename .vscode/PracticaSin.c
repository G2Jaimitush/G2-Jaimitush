#include <stdio.h>

// Función para calcular la raíz cuadrada sin math.h
float raiz_cuadrada(float discriminante) {
    float x = discriminante;
    float y = 1;
    float e = 0.00001;  // Precisión

    if (discriminante == 0) return 0;

    while (x - y > e) {
        x = (x + y) / 2;
        y = discriminante / x;
    }

    return x;
}

int main() {
    // Definicion de variables
    int a = 0, b = 0, c = 0;

    // El usuario ingresa los valores de a, b y c
    printf("Calcular una ecuacion de segundo grado mediante la formula general\n");
    printf("ax^2 + bx + c = 0\n");
    printf("La formula general es: x = (-b +- sqrt(b^2 - 4ac)) / 2a\n");
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de b: ");
    scanf("%d", &b);
    printf("Ingrese el valor de c: ");
    scanf("%d", &c);

    // Se calcula el discriminante
    int discriminante = (b * b) - (4 * a * c);
    
    printf("El discriminante es: %d\n", discriminante);

    if (discriminante > 0) {
        printf("La ecuacion tiene dos soluciones reales y diferentes\n");
        float raiz = raiz_cuadrada(discriminante);
        float x1 = (-b + raiz) / (2.0*a);
        float x2 = (-b - raiz) / (2.0*a);
        printf ("La solucion es: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else if (discriminante == 0) {
        printf("La ecuacion tiene una solucion real doble\n");
        float raiz = raiz_cuadrada(discriminante);  // será 0
        float x1 = (-b + raiz) / (2.0*a);
        printf ("La solucion es: x1 = %.2f\n", x1);
    } else {
        printf("La ecuacion no tiene soluciones reales\n");
        printf("No se puede calcular la raiz cuadrada de un discriminante negativo en numeros reales.\n");
    }

    return 0;
}
