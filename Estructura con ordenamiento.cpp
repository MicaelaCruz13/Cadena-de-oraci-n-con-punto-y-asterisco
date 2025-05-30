#include <stdio.h>
#define nro 5

struct cuentas {
	int nro_cuenta;
	char nombre[30];
	int saldo;
};

// Función para ordenar por número de cuenta usando Bubble Sort
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
	
	// Sumar todos los saldos
	for (i = 0; i < nro; i++) {
		total_saldos += cuen[i].saldo;
	}
	
	// Ordenar cuentas por número de cuenta
	ordenar_por_nro_cuenta(cuen, nro);
	
	// Mostrar resultados
	printf("\n--- Cuentas ordenadas por número de cuenta ---\n");
	for (i = 0; i < nro; i++) {
		printf("Cuenta: %d | Nombre: %s | Saldo: %d\n", cuen[i].nro_cuenta, cuen[i].nombre, cuen[i].saldo);
	}
	
	printf("\nCantidad de deudores: %d\n", deudor);
	printf("Cantidad de acreedores: %d\n", acreedor);
	printf("Total de todos los saldos: %d\n", total_saldos);
	
	return 0;
}
