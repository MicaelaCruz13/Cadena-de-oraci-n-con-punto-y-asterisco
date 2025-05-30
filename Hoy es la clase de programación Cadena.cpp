#include <stdio.h>
#include <string.h>

#define MAX_CADENA 100

int main() {
	char s1[MAX_CADENA], s2[MAX_CADENA], resultado[MAX_CADENA * 2];
	
	// Ingreso de las cadenas
	printf("Ingrese la primera cadena (s1): ");
	fgets(s1, MAX_CADENA, stdin);
	s1[strcspn(s1, "\n")] = 0; // Eliminar el salto de línea al final
	
	printf("Ingrese la segunda cadena (s2): ");
	fgets(s2, MAX_CADENA, stdin);
	s2[strcspn(s2, "\n")] = 0; // Eliminar el salto de línea al final
	
	// Mostrar el contenido de las cadenas
	printf("\nCadena 1: %s\n", s1);
	printf("Cadena 2: %s\n", s2);
	
	// Determinar cuál es más larga
	char *masLarga, *masCorta;
	if (strlen(s1) >= strlen(s2)) {
		masLarga = s1;
		masCorta = s2;
	} else {
		masLarga = s2;
		masCorta = s1;
	}
	
	printf("\nLa cadena más larga es: %s\n", masLarga);
	
	// Concatenar la cadena más larga a la más corta con un espacio en medio
	strcpy(resultado, masCorta);
	strcat(resultado, " "); // Agregar un espacio antes de concatenar
	strcat(resultado, masLarga);
	
	printf("\nConcatenación (más corta + espacio + más larga): %s\n", resultado);
	
	return 0;
}
