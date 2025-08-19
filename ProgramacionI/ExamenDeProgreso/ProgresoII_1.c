#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_ESTUDIANTES 5
#define EXAMENES 5

struct Estudiante {
    char nombre[30];
    float notas[EXAMENES];
    float promedio;
    float desviacion;
};

float calcular_promedio(float notas[], float pesos[], int num_examenes) {
    float suma = 0.0;
    for (int i = 0; i < num_examenes; i++) {
        suma += notas[i] * pesos[i];
    }
    return suma;
}

int main() {
    struct Estudiante estudiantes[MAX_ESTUDIANTES];
    float pesos[EXAMENES];
    int num_estudiantes = 0;
    float validacion;

    VERIFICAR:
    printf("Ingrese el numero de estudiantes (MAXIMO 5 ESTUDIANTES): ");
    scanf("%d", &num_estudiantes);
    getchar(); // Limpia el salto de linea despues de scanf
    if (num_estudiantes < 1 || num_estudiantes > MAX_ESTUDIANTES) {
        printf("El numero de estudiantes debe estar entre 1 y %d. Intente nuevamente.\n", MAX_ESTUDIANTES);
        goto VERIFICAR;
    }

    REPETIR:
    validacion = 0;
    printf("Ingrese los pesos de los %d examenes (en decimales, deben sumar 1.00):\n", EXAMENES);
    for (int i = 0; i < EXAMENES; i++) {
        printf("Peso del examen %d: ", i + 1);
        scanf("%f", &pesos[i]);
        validacion += pesos[i];
    }

    // Verificacion sin fabs, usando margen de error
    if (validacion < 0.999 || validacion > 1.001) {
        printf("Los pesos deben sumar exactamente 1.0. Usted ingreso %.4f. Intente nuevamente.\n\n", validacion);
        goto REPETIR;
    }

    for (int i = 0; i < num_estudiantes; i++) {
        getchar(); // Limpiar buffer
        printf("\nIngrese el nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i].nombre, sizeof(estudiantes[i].nombre), stdin);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = 0; // Quita el salto de linea

        for (int j = 0; j < EXAMENES; j++) {
            printf("Nota del examen %d: ", j + 1);
            scanf("%f", &estudiantes[i].notas[j]);
            if (estudiantes[i].notas[j] < 0 || estudiantes[i].notas[j] > 10) {
                printf("La nota debe estar entre 0 y 10. Intente nuevamente.\n");
                j--; // Repetir la entrada para este examen
            }
        }

        estudiantes[i].promedio = calcular_promedio(estudiantes[i].notas, pesos, EXAMENES);
    }

    // Calcular la media de la clase
    float suma_total = 0;
    for (int i = 0; i < num_estudiantes; i++) {
        suma_total += estudiantes[i].promedio;
    }
    float media_clase = suma_total / num_estudiantes;

    // Calcular desviacion
    for (int i = 0; i < num_estudiantes; i++) {
        estudiantes[i].desviacion = media_clase - estudiantes[i].promedio;
    }

    // Mostrar resultados
    printf("\nNombre\t\tNotas\t\t\t\t\tPromedio\t\t\t\tDesviacion\n");
    for (int i = 0; i < num_estudiantes; i++) {
        printf("%-15s", estudiantes[i].nombre);
        for (int j = 0; j < EXAMENES; j++) {
            printf("%.0f ", estudiantes[i].notas[j]);
        }

        printf("\t( ");
        for (int j = 0; j < EXAMENES; j++) {
            printf("%.0f*%.2f", estudiantes[i].notas[j], pesos[j]);
            if (j != EXAMENES - 1) printf(" + ");
        }
        printf(" ) = %.2f\t", estudiantes[i].promedio);
        printf("\t%.2f\n", fabs(estudiantes[i].desviacion));
    }

    printf("\nMedia de la clase = %.2f\n", media_clase);

    return 0;
}
