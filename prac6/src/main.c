#include <stdio.h>
#include "Colacircular.h"


int menu();

int main()
{

	int  op = 0;
	CCircular *c;
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
			encolar(c, info);
			imprimir(c);
			break;
		case 3:
			desencolar(c);
			imprimir(c);
			break;
		case 4:
			borrar_cola(c);
			break;
		case 5:
			primero(c);		
		default:
			break;
		}
	}while(op!=6);

	return (0);
}


int menu(){
	int opcion;
	printf("Selecciona una opción\n");
	printf("1. Crear Cola\n");
	printf("2. Encolar\n");
	printf("3. Desencolar\n");
	printf("4. Anular\n");
	printf("5. Primero\n");
	printf("6. Salir\n");
	scanf("%d", &opcion);
	return opcion;
}