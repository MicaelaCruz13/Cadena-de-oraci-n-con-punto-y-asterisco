#include <stdio.h>
#include <string.h>
#define nro 5

struct cuentas {
	int nro_cuenta;
	char nombre[30];
	int saldo;
};

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

int busqueda_binaria(struct cuentas arr[], int n, int buscado) {
	int inicio = 0, fin = n - 1, medio;
	
	while (inicio <= fin) {
		medio = (inicio + fin) / 2;
		
		if (arr[medio].nro_cuenta == buscado)
			return medio;
		else if (arr[medio].nro_cuenta < buscado)
			inicio = medio + 1;
		else
			fin = medio - 1;
	}
	return -1;
}

int main() {
	struct cuentas cuen[nro];
	int i, deudor = 0, acreedor = 0;
	int total_saldos = 0;
	
	// ?? NUEVO: variables para encontrar el mayor deudor/acreedor
	int indice_mayor_deudor = -1;
	int indice_mayor_acreedor = -1;
	
	for (i = 0; i < nro; i++) {
		printf("Ingrese Nro de Cuenta: ");
		scanf("%d", &cuen[i].nro_cuenta);
		
		printf("Ingrese nombre del cliente: ");
		scanf("%s", cuen[i].nombre);
		
		printf("Ingrese saldo del cliente: ");
		scanf("%d", &cuen[i].saldo);
		printf("\n");
		
		total_saldos += cuen[i].saldo;
		
		if (cuen[i].saldo < 0) {
			deudor++;
			// ?? Buscar el mayor saldo deudor (más cercano a 0)
			if (indice_mayor_deudor == -1 || cuen[i].saldo > cuen[indice_mayor_deudor].saldo) {
				indice_mayor_deudor = i;
			}
		} else if (cuen[i].saldo > 0) {
			acreedor++;
			// ?? Buscar el mayor saldo acreedor
			if (indice_mayor_acreedor == -1 || cuen[i].saldo > cuen[indice_mayor_acreedor].saldo) {
				indice_mayor_acreedor = i;
			}
		}
	}
	
	ordenar_por_nro_cuenta(cuen, nro);
	
	printf("\n--- Cuentas ordenadas por número de cuenta ---\n");
	for (i = 0; i < nro; i++) {
		printf("Cuenta: %d | Nombre: %s | Saldo: %d\n", cuen[i].nro_cuenta, cuen[i].nombre, cuen[i].saldo);
	}
	
	printf("\nCantidad de deudores: %d\n", deudor);
	printf("Cantidad de acreedores: %d\n", acreedor);
	printf("Total de todos los saldos: %d\n", total_saldos);
	
	// ?? Mostrar cuenta con mayor saldo deudor
	if (indice_mayor_deudor != -1) {
		printf("\nCuenta con mayor saldo deudor:\n");
		printf("Cuenta: %d | Nombre: %s | Saldo: %d\n",
			   cuen[indice_mayor_deudor].nro_cuenta,
			   cuen[indice_mayor_deudor].nombre,
			   cuen[indice_mayor_deudor].saldo);
	}
	
	// ?? Mostrar cuenta con mayor saldo acreedor
	if (indice_mayor_acreedor != -1) {
		printf("\nCuenta con mayor saldo acreedor:\n");
		printf("Cuenta: %d | Nombre: %s | Saldo: %d\n",
			   cuen[indice_mayor_acreedor].nro_cuenta,
			   cuen[indice_mayor_acreedor].nombre,
			   cuen[indice_mayor_acreedor].saldo);
	}
	
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
