
#include <stdio.h>
#include <string.h>
#include <ctype.h>
	
	// Función que cuenta la cantidad de vocales en una cadena
	int contar_vocales(char cadena[]) {
	int i, contador = 0;
	char c;
	for (i = 0; cadena[i] != '\0'; i++) {
		c = tolower(cadena[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			contador++;
		}
	}
	return contador;
}
	
	// Función que invierte la cadena y la almacena en otra
	void invertir_cadena(char original[], char invertida[]) {
		int len = strlen(original);
		int i;
		for (i = 0; i < len; i++) {
			invertida[i] = original[len - 1 - i];
		}
		invertida[len] = '\0'; // No olvidar el carácter nulo
	}
	
	int main() {
		char cadena[100];
		char invertida[100];
		
		printf("Ingrese una cadena: ");
		fgets(cadena, sizeof(cadena), stdin);
		
		// Eliminar salto de línea si lo hay
		size_t ln = strlen(cadena) - 1;
		if (cadena[ln] == '\n') cadena[ln] = '\0';
		
		printf("Cantidad de vocales: %d\n", contar_vocales(cadena));
		
		invertir_cadena(cadena, invertida);
		printf("Cadena invertida: %s\n", invertida);
		
		return 0;
	}
