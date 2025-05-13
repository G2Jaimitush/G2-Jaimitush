#include<stdio.h>
int main()
{
	int a,b,i,j;
	printf("Ingrese el largo: ");
	scanf("%d",&a);
	printf("Ingrese el ancho: ");
	scanf("%d",&b);
	int Matriz1[a][b];
	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			printf("Ingrese el valor para Matriz1[%d][%d]: ",i,j);
			scanf("%d",&Matriz1[i][j]);
		}
	}
	for(i=0; i<a; i++) {
		printf("\n");
		printf("{");
		for(j=0; j<b; j++) {
			printf("%d ",Matriz1[i][j]);
		}
		printf("}");
	}

	printf("\n");
	int k=0,aux;
	int Vector1[a*b];
	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			Vector1[k]=Matriz1[i][j];
			k++;
		}
	}
	printf("\nMatriz organizada: \n");
	for(i=0; i<(a*b); i++) {
		for(j=i+1; j<(a*b); j++) {
			if(Vector1[i]<Vector1[j]) {
				aux=Vector1[i];
				Vector1[i]=Vector1[j];
				Vector1[j]=aux;
			}
		}
	}
	k=0;
	for(i=0; i<a; i++) {
		printf("\n");
		printf("{");
		for(j=0; j<b; j++) {
			printf(" %d ",Vector1[k]);
			k++;
		}
		printf("}");
	}
}