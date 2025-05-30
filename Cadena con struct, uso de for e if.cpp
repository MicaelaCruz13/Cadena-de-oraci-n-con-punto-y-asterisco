#include <stdio.h>
#include <conio.h>
#define nro 5

struct cuentas
{
	int nro_cuenta;
	char nombre[30];
	int saldo;
};

int main()
{
	struct cuentas cuen[nro];
	int i, deudor = 0, acreedor = 0;
	
	for (i = 0; i < nro; i++)
	{
		printf("Ingrese Nro de Cuenta: ");
		scanf("%i", &cuen[i].nro_cuenta);
		
		printf("Ingrese nombre del cliente: ");
		scanf("%s", cuen[i].nombre);
		
		printf("Ingrese saldo del cliente: ");
		scanf("%d", &cuen[i].saldo);
		printf("\n");
	}
	
	
	for (i = 0; i < nro; i++)
	{
		if (cuen[i].saldo < 0)
		{
			deudor++;
		}
		else
		{
			acreedor++;
		}
	}
	
	printf("\n--- Resumen de Saldos ---\n");
	printf("Cantidad de cuentas deudoras: %d\n", deudor);
	printf("Cantidad de cuentas acreedoras: %d\n", acreedor);
	
	return 0;

	
}
	
