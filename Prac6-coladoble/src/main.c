#include <stdio.h>
#include "ColaDoble.h"


int menu();

int main()
{

	int  op = 0;
	CDoble *c;
	item info;
	do{
		op = menu();
		switch (op)
		{
		case 1:
			c = crear_cola();
			break;
		case 2:
			printf("Ingresa el dato a insertar en la Cola\n");
			scanf("%d", &info);
			encolar_incio(c, info);
			imprimir(c);
			break;
		case 3:
			desencolar_inicio(c);
			imprimir(c);
			break;
		case 4:
			printf("Ingresa el dato a insertar en la Cola\n");
			scanf("%d", &info);
			encolar_fin(c, info);
			imprimir(c);
			break;
		case 5:
			desencolar_fin(c);
			imprimir(c);
			break;
		case 6:
			borrar_cola(c);
			break;
		case 7:
			primero(c);
			break;
		default:
			break;
		}
	}while(op!=8);

	return (0);
}


int menu(){
	int opcion;
	printf("Selecciona una opción\n");
	printf("1. Crear Cola\n");
	printf("2. Encolar Inicio\n");
	printf("3. Desencolar Inicio\n");
	printf("4. Encolar Final\n");
	printf("5. Desencolar Final\n");
	printf("6. Anular\n");
	printf("7. Primero\n");
	printf("8. Salir\n");
	scanf("%d", &opcion);
	return opcion;
}