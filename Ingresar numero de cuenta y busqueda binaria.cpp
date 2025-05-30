#include <stdio.h>
#include <string.h>
#define nro 5

struct cuentas {
	int nro_cuenta;
	char nombre[30];
	int saldo;
};

// Ordenar por número de cuenta
void ordenar_por_nro_cuenta(struct cuentas arr[], int n) {
	int i, j;
	struct cuentas temp;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j].nro_cuenta > arr[j + 1].nro_cuenta) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Búsqueda binaria por número de cuenta
int busqueda_binaria(struct cuentas arr[], int n, int buscado) {
	int inicio = 0, fin = n - 1, medio;
	
	while (inicio <= fin) {
		medio = (inicio + fin) / 2;
		
		if (arr[medio].nro_cuenta == buscado)
			return medio; // encontrado
		else if (arr[medio].nro_cuenta < buscado)
			inicio = medio + 1;
		else
			fin = medio - 1;
	}
	return -1; // no encontrado
}

int main() {
	struct cuentas cuen[nro];
	int i, deudor = 0, acreedor = 0;
	int total_saldos = 0;
	
	// Ingreso de datos
	for (i = 0; i < nro; i++) {
		printf("Ingrese Nro de Cuenta: ");
		scanf("%d", &cuen[i].nro_cuenta);
		
		printf("Ingrese nombre del cliente: ");
		scanf("%s", cuen[i].nombre);
		
		printf("Ingrese saldo del cliente: ");
		scanf("%d", &cuen[i].saldo);
		printf("\n");
		
		if (cuen[i].saldo < 0)
			deudor++;
		else if (cuen[i].saldo > 0)
			acreedor++;
	}
	
	// Sumar saldos
	for (i = 0; i < nro; i++) {
		total_saldos += cuen[i].saldo;
	}
	
	// Ordenar por número de cuenta
	ordenar_por_nro_cuenta(cuen, nro);
	
	// Mostrar cuentas ordenadas
	printf("\n--- Cuentas ordenadas por número de cuenta ---\n");
	for (i = 0; i < nro; i++) {
		printf("Cuenta: %d | Nombre: %s | Saldo: %d\n", cuen[i].nro_cuenta, cuen[i].nombre, cuen[i].saldo);
	}
	
	printf("\nCantidad de deudores: %d\n", deudor);
	printf("Cantidad de acreedores: %d\n", acreedor);
	printf("Total de todos los saldos: %d\n", total_saldos);
	
	// Búsqueda binaria
	int cuenta_a_buscar;
	printf("\nIngrese el número de cuenta que desea buscar: ");
	scanf("%d", &cuenta_a_buscar);
	
	int pos = busqueda_binaria(cuen, nro, cuenta_a_buscar);
	
	if (pos != -1) {
		printf("Cuenta encontrada:\n");
		printf("Número: %d | Nombre: %s | Saldo: %d\n", cuen[pos].nro_cuenta, cuen[pos].nombre, cuen[pos].saldo);
	} else {
		printf("La cuenta %d no fue encontrada.\n", cuenta_a_buscar);
	}
	
	return 0;
}
