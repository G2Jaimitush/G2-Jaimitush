#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *file;
    char *filename = "C:\\Users\\jaime\\Documents\\Ejercicios VSCode\\.vscode\\Archivos\\Archivos.txt"; // Ruta del archivo a crear
    char *message = "Este es un archivo de prueba.";

    // Crear y abrir el archivo para escritura, siempre poner esto al crear un archivo
    file = fopen(filename, "w");
    if (file == NULL) { // Verificar si el archivo se creó correctamente
        printf("Error al crear el archivo");
        return 1;
    }

    //Escribir el mensaje en el archivo
    fputs(message, file);


    // Cerrar el archivo
    fclose(file);

    //Validar que el archivo se creó correctamente
    file = fopen(filename, "r");
    if (file){
        printf("El archivo se creo correctamente.\n");
        fclose(file); // Cerrar el archivo después de la validación
    } else {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }
}