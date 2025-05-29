#include <stdio.h>

struct CalculoPromedio {
    float num1, num2, num3;
};

// Función que recibe un puntero a la estructura y devuelve el promedio
float Promedio(struct CalculoPromedio *ptr) {
    float promedio = (ptr->num1 + ptr->num2 + ptr->num3) / 3;
    return promedio;
}

int main() {
    struct CalculoPromedio calculopromedio;
    struct CalculoPromedio *ptr = &calculopromedio;

    printf("Ingrese el primer número: ");
    scanf("%f", &ptr->num1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &ptr->num2);

    printf("Ingrese el tercer número: ");
    scanf("%f", &ptr->num3);

    float promedio = Promedio(ptr);

    printf("El promedio es: %.2f\n", promedio);

    return 0;
}
