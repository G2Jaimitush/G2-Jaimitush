#include <stdio.h>

struct Estudiante {
    char nombre[50];
    char apellido[50];
    int edad;
    float promedio;
};

int main (){
    struct Estudiante estudiante1;


    //Asignacion de valores a la estructura
    printf ("Ingrese el nombre del estudiante: ");
    fgets (estudiante1.nombre, 50, stdin);
    //scanf ("%s", estudiante1.nombre);
    //gets (estudiante1.nombre);
    //Con las 3 funciones anteriores se puede ingresar el nombre

    printf ("Ingrese el apellido del estudiante: ");
    fgets (estudiante1.apellido, 50, stdin);
    printf ("Ingrese la edad del estudiante: ");
    scanf ("%d", &estudiante1.edad);
    printf ("Ingrese el promedio del estudiante: ");
    scanf ("%f", &estudiante1.promedio);

    printf ("-------------------------------\n");
    
    //Mostrar la informacion del estudiante
    printf ("Informacion del estudiante:\n");
    printf ("Nombre: %s", estudiante1.apellido);
    printf ("Nombre: %s", estudiante1.nombre);
    printf ("Edad: %d\n", estudiante1.edad);
    printf ("Promedio: %.2f\n", estudiante1.promedio);
    
    return 0;
}