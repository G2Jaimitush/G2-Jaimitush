#include <stdio.h>
#include <string.h>
#include <math.h>

#define PROGRESOI 0.25
#define PROGRESOII 0.35
#define PROGRESOIII 0.40
#define MAX_3_PROGRESOS 3
struct Materia{
    char NombreMateria[50];
    int ponderacion;
    float ProgresoI;
    float ProgresoII;
    float ProgresoIII;
    float PromedioFinal;
};

void MenuDeUsuario ();
void RegistroDeArchivoOpcion1 (int OpcionArchivo);
void RegistroDeArchivoOpcion2 ();
void MenuDeOpcionesOpcione2(struct Materia *Materias, int CantidadMaterias, char *NombreArchivo);
void DesplegarMateriasRegistradas (struct Materia *materias, int cantidadMaterias);
void CalcularPromedioDeProgreso (struct Materia *materia, int CantidadMaterias, char *NombreArchivo);
void PromedioFinalTodasMaterias (struct Materia *materia, int CantidadMaterias);

void MenuDeUsuario (){

    int OpcionArchivo = 0;

    printf ("Bienvenido a la plataforma para calcular tu promedio\n");

    do{
        printf ("Seleccione una opcion:\n");
        printf ("1. Tengo un archivo existente\n");
        printf ("2. No tengo un archivo existente\n");
        printf ("3. Salir\n");
        printf ("Opcion: ");
        scanf ("%d",&OpcionArchivo);

        if (OpcionArchivo == 1){
            RegistroDeArchivoOpcion1 (OpcionArchivo);
        }else if (OpcionArchivo == 2){
            RegistroDeArchivoOpcion2 ();
        }
    }while (OpcionArchivo != 3);

}

void RegistroDeArchivoOpcion1(int OpcionArchivo){
    char NombreArchivo[50];
    FILE *archivo;

    if (OpcionArchivo == 1) {
        printf("Usted ha seleccionado que tiene un archivo existente\n");
        printf("Cual es el nombre del archivo? Tiene que ser exacto a como fue guardado: ");
        getchar();  // Limpiar buffer
        fgets(NombreArchivo, sizeof(NombreArchivo), stdin);
        NombreArchivo[strcspn(NombreArchivo, "\n")] = '\0';  // Eliminar salto de línea
        strcat(NombreArchivo, ".txt");  // Añadir extensión

        archivo = fopen(NombreArchivo, "r"); 
        if (archivo != NULL) {
            printf("El archivo '%s' fue encontrado correctamente.\n", NombreArchivo);

            // Leer materias desde el archivo
            struct Materia materias[50];
            int cantidad = 0;

            while (fscanf(archivo, "%49[^\n]\n%d\n%f\n%f\n%f\n", 
                        materias[cantidad].NombreMateria,
                        &materias[cantidad].ponderacion,
                        &materias[cantidad].ProgresoI,
                        &materias[cantidad].ProgresoII,
                        &materias[cantidad].ProgresoIII) == 5) {
                // Calcular promedio de la materia
                materias[cantidad].PromedioFinal = (materias[cantidad].ProgresoI * PROGRESOI) +
                                                   (materias[cantidad].ProgresoII * PROGRESOII) +
                                                   (materias[cantidad].ProgresoIII * PROGRESOIII);
                cantidad++;
            }

            fclose(archivo);

            // Imprimir tabla de materias
            printf("\n%-45s | %-10s | %-10s | %-10s | %-10s | %-10s\n", 
                   "Materia", "Ponderacion", "Progreso I", "Progreso II", "Progreso III", "Promedio");
            printf("------------------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < cantidad; i++) {
                printf("%-45s | %-10d | %-10.2f | %-10.2f | %-10.2f | %-10.2f\n",
                       materias[i].NombreMateria,
                       materias[i].ponderacion,
                       materias[i].ProgresoI,
                       materias[i].ProgresoII,
                       materias[i].ProgresoIII,
                       materias[i].PromedioFinal);
            }

            // Calcular promedio final del semestre
            float PromedioGeneral = 0.0;
            int SumaPonderaciones = 0;
            for (int i = 0; i < cantidad; i++) {
                SumaPonderaciones += materias[i].ponderacion;
                PromedioGeneral += materias[i].PromedioFinal * materias[i].ponderacion;
            }
            if (SumaPonderaciones != 0) {
                PromedioGeneral /= SumaPonderaciones;
                printf("\nPromedio final del semestre: %.2f\n", PromedioGeneral);
            } else {
                printf("\nNo se pudieron calcular promedios (suma de ponderaciones = 0).\n");
            }

        } else {
            printf("No se encontro el archivo '%s'. Verifique el nombre.\n", NombreArchivo);
        }
    }
}


void RegistroDeArchivoOpcion2 (){

    int CantidadMaterias = 0;
    int OpcionArchivo = 0;
    float CantidadMaterias_Evaluar = 0;
    char NombreArchivo[50];

    printf ("Usted ha seleccionado que no tiene un archivo existente\n");
    printf ("Creemos el archivo para usted\n");
    printf ("Cual es el nombre del archivo que desea crear? (sin extension): ");
    getchar();
    fgets(NombreArchivo, sizeof(NombreArchivo), stdin);
    NombreArchivo[strcspn(NombreArchivo, "\n")] = '\0';
    strcat(NombreArchivo, ".txt");

    do{
        REPETIR_CANTIDAD_MATERIAS:
        printf ("Ingresa la cantidad de materias a registrar (7 como maximo): ");
        scanf ("%f",&CantidadMaterias_Evaluar);
        
        if (ceilf(CantidadMaterias_Evaluar) != CantidadMaterias_Evaluar){
            printf ("No se permite ingresar decimales. Intentalo nuevamente\n");
            goto REPETIR_CANTIDAD_MATERIAS;
        }
        
        CantidadMaterias = (int)CantidadMaterias_Evaluar;    
    
        if (CantidadMaterias > 7 || CantidadMaterias < 0){
               printf ("Solo se permite el ingreso e maximo 7 materias\n");
        }

    }while ((CantidadMaterias > 7 || CantidadMaterias < 0));

    struct Materia Materias[CantidadMaterias];
    

    FILE *archivo;

    archivo = fopen(NombreArchivo, "w");
    //Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    for (int i = 0; i < CantidadMaterias; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        getchar(); // Limpiar el buffer
        fgets(Materias[i].NombreMateria, sizeof(Materias[i].NombreMateria), stdin);
        Materias[i].NombreMateria[strcspn(Materias[i].NombreMateria, "\n")] = '\0';

        //Guardar en el archivo
        fprintf(archivo, "%s\n", Materias[i].NombreMateria);

        //PONDERACION
        printf ("Ingrese la ponderacion de la materia de %s: ", Materias[i].NombreMateria);
        scanf ("%d",&Materias[i].ponderacion);

        fprintf(archivo, "%d\n", Materias[i].ponderacion);

        //Progreso I
        printf ("Ingrese la nota del Progreso I (0 - 10): ");
        scanf ("%f",&Materias[i].ProgresoI);
        while (Materias[i].ProgresoI < 0 || Materias[i].ProgresoI > 10){
            printf ("La nota del Progreso I debe estar entre 0 y 10. Intentalo nuevamente: ");
            scanf ("%f",&Materias[i].ProgresoI);
        }

        fprintf(archivo, "%.2f\n", Materias[i].ProgresoI);


        //PROGRESO II
        printf ("Ingrese la nota del Progreso II (0 - 10): ");
        scanf ("%f",&Materias[i].ProgresoII);
        while (Materias[i].ProgresoII < 0 || Materias[i].ProgresoII > 10){
            printf ("La nota del Progreso II debe estar entre 0 y 10. Intentalo nuevamente: ");
            scanf ("%f",&Materias[i].ProgresoII);
        }

        fprintf(archivo, "%.2f\n", Materias[i].ProgresoII);

        //PROGRESO III
        printf ("Ingrese la nota del Progreso III (0 - 10): ");
        scanf ("%f",&Materias[i].ProgresoIII);
        while (Materias[i].ProgresoIII < 0 || Materias[i].ProgresoIII > 10){
            printf ("La nota del Progreso III debe estar entre 0 y 10. Intentalo nuevamente: ");
            scanf ("%f",&Materias[i].ProgresoIII);
        }

        fprintf(archivo, "%.2f\n", Materias[i].ProgresoIII);
    }
    
    fclose(archivo);

    printf ("Materias registradas correctamente en el archivo %s\n", NombreArchivo);
    DesplegarMateriasRegistradas (Materias, CantidadMaterias);
    MenuDeOpcionesOpcione2(Materias, CantidadMaterias, NombreArchivo);
}


void MenuDeOpcionesOpcione2(struct Materia *Materias, int CantidadMaterias, char *NombreArchivo){

    int OpcionArchivo = 0;

    do{
        printf ("Seleccione una opcion:\n");
        printf ("1. Ver materias registradas\n");
        printf ("2. Calcular promedio final de una materia\n");
        printf ("3. Calcular promedio general de todas las materias\n");
        printf ("4. Salir\n");
        printf ("Opcion: ");
        scanf ("%d",&OpcionArchivo);

        switch (OpcionArchivo)
        {
        case 1:
            DesplegarMateriasRegistradas (Materias, CantidadMaterias);
            break;
        
        case 2:
            CalcularPromedioDeProgreso(Materias, CantidadMaterias, NombreArchivo);
            break;
        case 3:
            PromedioFinalTodasMaterias (Materias, CantidadMaterias);
            break;
        
        case 4:
            printf ("Saliendo del programa...\n");
            break;

        default:
            printf ("Opcion Invalida\n");
            break;
        }

    }while (OpcionArchivo != 4);

}

void DesplegarMateriasRegistradas (struct Materia *materias, int cantidadMaterias){
    printf ("Materias registradas:\n");
    for (int i = 0; i < cantidadMaterias; i++){
        printf ("%d. %s\n", i + 1, materias[i].NombreMateria);
        printf ("\t Ponderacion: %d\n", materias[i].ponderacion);
        printf ("\t Progreso I: %.2f\n", materias[i].ProgresoI);
        printf ("\t Progreso II: %.2f\n", materias[i].ProgresoII);
        printf ("\t Progreso III: %.2f\n",materias[i].ProgresoIII);
    }
}


void CalcularPromedioDeProgreso (struct Materia *materia, int CantidadMaterias, char *NombreArchivo){
    int opc;
    
    do{
        printf ("Desea realizar los promedios de todas las materias? Si (1) No (2): "); scanf ("%d",&opc);
        if (opc == 1){
            printf ("Realizando los promedios de cada materia...\n");
            for (int i = 0; i < CantidadMaterias; i++){
                materia[i].PromedioFinal = (materia[i].ProgresoI * PROGRESOI) + (materia[i].ProgresoII * PROGRESOII) + (materia[i].ProgresoIII * PROGRESOIII);
                printf ("El promedio final de la materia %s es: %.2f\n", materia[i].NombreMateria, materia[i].PromedioFinal);
            }
                
            FILE *archivo;
            archivo = fopen(NombreArchivo, "a");
            if (archivo == NULL) {
                printf("No se pudo abrir el archivo para actualizar los promedios.\n");
                return;
            }
            fprintf(archivo, "\n -----------------------\n");
            fprintf (archivo, "Promedios Finales:\n");

            for (int i = 0; i < CantidadMaterias; i++){
                fprintf(archivo, " %s:  %.2f\n", materia[i].NombreMateria,materia[i].PromedioFinal);
            }
            fclose(archivo);
            printf ("Promedios finales guardados correctamente en el archivo %s\n", NombreArchivo);
            break;

        }else if (opc == 2){
            printf ("Saliendo del programa...\n");
            break;
        }else{
            printf ("Opcion Invalida\n");
        }
    }while (opc == 1 || opc == 2);
    
}

void PromedioFinalTodasMaterias (struct Materia *materia, int CantidadMaterias){

    int SumaPonderaciones = 0;
    float PromedioGeneral = 0.0;
    for (int i = 0; i < CantidadMaterias; i++){
        SumaPonderaciones += materia[i].ponderacion;
    }

    for (int i = 0; i < CantidadMaterias; i++){
        PromedioGeneral += materia[i].PromedioFinal * materia[i].ponderacion;
    }
    
    PromedioGeneral /= SumaPonderaciones;
    printf ("El promedio final del semestres: %.2f\n", PromedioGeneral);

}

void Adicional (struct Materia *materia, int CantidadMaterias, char *NombreArchivo, float PromedioGeneral){
    FILE *archivo;
    archivo = fopen(NombreArchivo, "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para actualizar el promedio general.\n");
        return;
    }
    fprintf(archivo, "\n -----------------------\n");
    fprintf (archivo, "Promedio Final del Semestre: %.2f\n", PromedioGeneral);
    fclose(archivo);

}

