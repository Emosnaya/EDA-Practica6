#ifndef __COLA_DOBLE_H__
#define __COLA_DOBLE_H__
#include "Nodo.h"



typedef struct lista CDoble;

struct lista{
    NODO *primero;
    NODO *ultimo;
    int longitud;
};

CDoble* crear_cola();
bool borrar_cola(CDoble*);
bool vaciar(CDoble*);
bool es_vacia(CDoble*);
item primero(CDoble*);
bool desencolar(CDoble*);

bool encolar_incio(CDoble*, item);
bool desencolar_inicio(CDoble*);


bool encolar_fin(CDoble*, item);
bool desencolar_fin(CDoble*);


void imprimir(CDoble*);

#endif