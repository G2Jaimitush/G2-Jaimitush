#include <stdio.h>
#include <math.h>

void calcularRaices(float a, float b, float c, float *raiz1, float *raiz2) {
    float discriminante = b * b - 4 * a * c;

    if (discriminante < 0) {
        printf("No tiene raíces reales.\n");
        *raiz1 = *raiz2 = 0; // Por seguridad
    } else {
        *raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        *raiz2 = (-b - sqrt(discriminante)) / (2 * a);
    }
}

int main() {
    float a, b, c, r1, r2;

    printf("Ingrese los coeficientes a, b y c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("No es una ecuación cuadrática.\n");
        return 1;
    }

    calcularRaices(a, b, c, &r1, &r2);

    printf("Raíz 1: %.2f\n", r1);
    printf("Raíz 2: %.2f\n", r2);

    return 0;
}
