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
	int i, deudor=0,acreedor=0;
	
	for (i=0; i < nro;i++)
	{
		printf("Ingrese Nro de Cuenta\n");
		scanf("%i",&cuen[i].nro_cuenta);
		
		printf("Ingrese nombre del cliente\n");
		scanf("%s", &cuen[i].nombre);
		
		printf("Ingrese saldo del cliente\n");
		scanf ("%d",&cuen[i].saldo);
		printf("\n");
	}
	
	return 0;
}
