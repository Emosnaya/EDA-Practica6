#ifndef __COLA_CIRCULAR_H__
#define __COLA_CIRCULAR_H__
#include "Nodo.h"



typedef struct lista CCircular;

struct lista{
    NODO *primero;
    NODO *ultimo;
    int longitud;
};

CCircular* crear_cola();
bool borrar_cola(CCircular*);
bool vaciar(CCircular*);
void imprimir(CCircular*);


bool es_vacia(CCircular*);
bool encolar(CCircular*, item);
bool desencolar(CCircular*);
item primero(CCircular*);




#endif