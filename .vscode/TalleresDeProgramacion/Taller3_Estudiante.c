#include <stdio.h>

int main()
{
    // Declaración de constantes, matrices, vectores y variables.
    const int NUM_ESTUDIANTES = 5;
    const int NUM_ASIGNATURAS = 3;
    float calificacion[NUM_ESTUDIANTES][NUM_ASIGNATURAS], nota_baja[NUM_ASIGNATURAS], nota_alta[NUM_ASIGNATURAS];
    double suma_materia[NUM_ASIGNATURAS], prom_materias[NUM_ASIGNATURAS];
    int i, j;
    float calificacion_est[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    float promedio[NUM_ESTUDIANTES], sumatoria[NUM_ESTUDIANTES], calificacion_mayor[NUM_ESTUDIANTES], calificacion_menor[NUM_ESTUDIANTES];
    int materia_baja[NUM_ESTUDIANTES], materia_alta[NUM_ESTUDIANTES];
    int aprobados = 0;  // Inicialización para evitar valores basura en el contador.
  
    printf("\t------- PROMEDIOS ESCOLARES ------\n\n");
    
    // Ingreso de calificaciones por estudiante en cada asignatura.
    printf("\tINGRESO DE CALIFICACIONES\n");
    for (i = 0; i < NUM_ESTUDIANTES; i++){ 
        // Inicialización de vectores para cada estudiante.
        sumatoria[i] = 0;
        calificacion_menor[i] = 11;
        calificacion_mayor[i] = -1;
        materia_alta[i] = 0;
        materia_baja[i] = 0;
        
        fflush(stdin); // Limpieza de buffer de entrada.
        printf("\nEstudiante %d:\n", i + 1);
       
        for (j = 0; j < NUM_ASIGNATURAS; j++){          
            do {
                printf("  Asignatura %d - Ingresa la calificacion (0 - 10): ", j + 1);
                scanf("%f", &calificacion_est[i][j]);
                calificacion[i][j] = calificacion_est[i][j];  // Datos que se usarán para promedios por materia.
                if (calificacion_est[i][j] < 0 || calificacion_est[i][j] > 10) {
                    printf("\tERROR: La calificacion debe estar entre 0 y 10.\n");
                }
            } while (calificacion_est[i][j] < 0 || calificacion_est[i][j] > 10);
            
            // Determinación de la materia con nota más baja y alta para el estudiante.
            if (calificacion_est[i][j] < calificacion_menor[i]) {
                calificacion_menor[i] = calificacion_est[i][j];
                materia_baja[i] = j + 1;  // Se suma 1 ya que las materias se numeran desde 1.
            }
            if (calificacion_est[i][j] > calificacion_mayor[i]) {
                 calificacion_mayor[i] = calificacion_est[i][j];
                 materia_alta[i] = j + 1;
            }     
        }
    }
    
    // Muestra de los resultados por estudiante.
    printf("\n---------------- RESULTADOS POR ESTUDIANTE ----------------\n");
    for (i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("-------------------------------------------------------------\n");
        for (j = 0; j < NUM_ASIGNATURAS; j++) {          
           printf("  Materia %d: %.2f\n", j + 1, calificacion_est[i][j]);
           sumatoria[i] += calificacion_est[i][j];
        }
        promedio[i] = sumatoria[i] / NUM_ASIGNATURAS;
        printf("  Promedio: %.3f\n", promedio[i]); 
        printf("  Nota mas alta: %.2f (Materia %d)\n", calificacion_mayor[i], materia_alta[i]);
        printf("  Nota mas baja: %.2f (Materia %d)\n", calificacion_menor[i], materia_baja[i]);

        if (promedio[i] >= 6) {
            aprobados++;
        }
    }
    printf("\n-------------------------------------------------------------\n");
    printf("Numero de estudiantes aprobados: %d\n", aprobados);
    printf("Numero de estudiantes reprobados: %d\n", NUM_ESTUDIANTES - aprobados);
    
    // Cálculo y despliegue del promedio, nota más baja y nota más alta por materia.
    printf("\n---------------- RESULTADOS POR MATERIA ----------------\n");
    for (j = 0; j < NUM_ASIGNATURAS; j++) {
        // Inicialización de la nota más baja y alta para la columna j.
        nota_baja[j] = calificacion[0][j];
        nota_alta[j] = calificacion[0][j];
        suma_materia[j] = 0;
        
        for (i = 0; i < NUM_ESTUDIANTES; i++) {
            suma_materia[j] += calificacion[i][j];
            if (calificacion[i][j] < nota_baja[j]) {
                nota_baja[j] = calificacion[i][j];
            }
            if (calificacion[i][j] > nota_alta[j]) {
                nota_alta[j] = calificacion[i][j];
            }
        }
        prom_materias[j] = suma_materia[j] / NUM_ESTUDIANTES;
        printf("\nAsignatura %d:\n", j + 1);
        printf("  Promedio: %.2f\n", prom_materias[j]);
        printf("  Nota mas baja: %.2f\n", nota_baja[j]);
        printf("  Nota mas alta: %.2f\n", nota_alta[j]);
    }
    printf("\n-------------------------------------------------------------\n");
    
    return 0;
}
