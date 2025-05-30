#include <stdio.h>

// Declaración de la función buscar
int buscar(int arr[], int n, int valor);

int main() {
	int arreglo[10];
	int i, valor, posicion;
	
	// Cargar el arreglo con 10 números enteros
	printf("Ingrese 10 numeros enteros:\n");
	for (i = 0; i < 10; i++) {
		printf("Numero %d: ", i + 1);
		scanf("%d", &arreglo[i]);
	}
	
	// Pedir el valor a buscar
	printf("\nIngrese el valor a buscar en el arreglo: ");
	scanf("%d", &valor);
	
	// Llamar a la función buscar
	posicion = buscar(arreglo, 10, valor);
	
	// Mostrar el resultado
	if (posicion != -1) {
		printf("El valor %d se encuentra en la posicion %d del arreglo.\n", valor, posicion);
	} else {
		printf("El valor %d no se encuentra en el arreglo.\n", valor);
	}
	
	return 0;
}

// Definición de la función buscar
int buscar(int arr[], int n, int valor) {
	int i; // Variable local
	for (i = 0; i < n; i++) {
		if (arr[i] == valor) {
			return i; // Devuelve la posición si encuentra el valor
		}
	}
	return -1; // Devuelve -1 si no lo encuentra
}
