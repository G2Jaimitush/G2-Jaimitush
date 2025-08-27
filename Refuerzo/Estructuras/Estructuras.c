#include <stdio.h>

struct Persona{
    char nombre[50];
    int edad;
};

//struct Persona p1;

int main (){

    struct Persona Personas [3];

    for (int i = 0; i < 3; i++){
        printf("Ingrese el nombre de la persona %d: ", i+1);
        scanf("%s", Personas[i].nombre);
        printf("Ingrese la edad de la persona %d: ", i+1);
        scanf("%d", &Personas[i].edad);
    }

}