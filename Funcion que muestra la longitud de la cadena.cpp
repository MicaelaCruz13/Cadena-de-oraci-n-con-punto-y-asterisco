#include <stdio.h>
#include <string.h>

int buscarCaracter(char cadena[], char buscar, const char *nombre) {
	for (int i = 0; i < strlen(cadena); i++) {
		if (cadena[i] == buscar) {
			printf("El caracter '%c' se encuentra en la %s cadena \"%s\"\n", buscar, nombre, cadena);
			return 1; // Indicar que se encontró el carácter
		}
	}
	return 0; // Indicar que no se encontró el carácter
}

int main() {
	char cadena1[100], cadena2[100], cadena3[100];
	char buscar;
	int encontrado = 0;
	
	// Solicitar al usuario que ingrese las cadenas
	printf("Introduce la primera cadena: ");
	scanf("%s", cadena1);
	printf("Introduce la segunda cadena: ");
	scanf("%s", cadena2);
	printf("Introduce la tercera cadena: ");
	scanf("%s", cadena3);
	
	// Mostrar la longitud de cada cadena
	printf("\nLongitudes de las cadenas:\n");
	printf("Primera cadena: %s (%lu caracteres)\n", cadena1, strlen(cadena1));
	printf("Segunda cadena: %s (%lu caracteres)\n", cadena2, strlen(cadena2));
	printf("Tercera cadena: %s (%lu caracteres)\n", cadena3, strlen(cadena3));
	
	// Solicitar al usuario que ingrese un carácter
	printf("\nIntroduce un caracter para buscar en las cadenas: ");
	scanf(" %c", &buscar);
	
	// Buscar en cada cadena
	encontrado += buscarCaracter(cadena1, buscar, "primera");
	encontrado += buscarCaracter(cadena2, buscar, "segunda");
	encontrado += buscarCaracter(cadena3, buscar, "tercera");
	
	if (encontrado == 0) {
		printf("El caracter '%c' no se encuentra en ninguna cadena.\n", buscar);
	}
	
	return 0;
}
