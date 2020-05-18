#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLON 1000

int main(int argc, char * argv[])
{
	FILE * fdescriptor;
  	char cadena[MAXLON];
	int aux_c;
 	int n_lineas;
	int count_lines = 0;
	

	if (argc != 3) {
		printf("Número de parametros inválido\n");
		return(1);
	}

	if (argv[1] < 0) {
		printf("Ingreso Numero de lineas: N válido");
		return(1);
	}
	n_lines = atoi(argv[1]);

	fdescriptor = fopen(argv[2], "r");

	if (fdescriptor == NULL) {
		printf("Problema para abrir el archivo");
		return(1);
	}

    
	do {
		//Contar el numero de las filas cuando encuentra un salto de linea
		if ((aux_c = fgetc(fdescriptor)) == '\n') {
			count_lines++;
		}

		//Condicional si el contador del lineas ya es igual 
		//al numero de lineas pedidas por el usuario 
		if (n_lines == count_lines) {
			break;
		}

		//Guarda el apuntador actual
		fseek(fdescriptor, -1, SEEK_CUR);

	}while(aux_!= EOF)

	//Imprime las cadenas hasta que se termine el archivo
	while (fgets(cadena, MAXLON, fdescriptor) != NULL) {
		printf("%s", cadena);
	}
	printf("\n");
}