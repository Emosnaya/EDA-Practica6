#ifndef __NODO_H__
#define __NODO_H__
#include <stdbool.h>

typedef int item;

struct _nodo{
    item dato;
    struct _nodo *siguiente;
};

typedef struct _nodo NODO;

NODO* crear_nodo(item);
bool borrar_nodo(NODO*);
bool actualizar_nodo(NODO*,item);

#endif // !__NODO_H__