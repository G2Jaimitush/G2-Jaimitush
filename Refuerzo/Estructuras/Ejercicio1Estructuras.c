#include <stdio.h>

struct Estudiante {
	char Nombre [64];
	float notas [10];
	float promedio;
};


int main() {
	int cantidad_Estudiantes;
	int cantidad_notas;
	float promedio_Estudiante = 0;
	float promedio_mayor;
	int posicion = 0;

	printf ("Ingrese la cantidad de Estudiantes que desea registrar: ");
	scanf ("%d",&cantidad_Estudiantes);

	printf ("Ingrese la cantidad de notas a registrar para cada estudiantes: ");
	scanf ("%d",&cantidad_notas);

	struct Estudiante Estudiantes [cantidad_Estudiantes];


	for (int i = 0; i < cantidad_Estudiantes; i++) {
		printf ("Ingrese el nombre de la persona %d: ", i + 1);
		getchar ();
		fgets (Estudiantes[i].Nombre, sizeof (Estudiantes[i].Nombre),stdin);
		printf ("Ingrese las notas del estudiantes %d\n", i + 1);
		promedio_Estudiante = 0;
		for (int j = 0; j < cantidad_notas; j++) {
			printf ("%d Nota: ",j + 1);
			scanf ("%f", &Estudiantes[i].notas[j]);
			promedio_Estudiante += Estudiantes[i].notas[j];
		}
		Estudiantes[i].promedio = promedio_Estudiante / cantidad_notas;
		printf ("El promedio del estudiantes %d es de: %f \n",i + 1, Estudiantes[i].promedio);

	}

    promedio_mayor = Estudiantes[0].promedio;
	for (int i = 1; i < cantidad_Estudiantes; i++) {
		if (Estudiantes[i].promedio > promedio_mayor) {
			promedio_mayor = Estudiantes[i].promedio;
			posicion = i;
		}
	}

    if (posicion != -1) {
        printf ("El estudiantes con mayor promedio es %d con un promedio de: %f",posicion,promedio_mayor);
    }

	return 0;
}
