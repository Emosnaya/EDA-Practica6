#include "Nodo.h"
#include <stdlib.h>

NODO* crear_nodo(item d){
    NODO * n1;
    n1 = (NODO*)malloc(sizeof(NODO));
    n1->dato = d;
    n1->siguiente = NULL;
    return n1;
}

bool borrar_nodo(NODO* n){
    if(n == NULL) return false;
    if(n->siguiente == NULL){
        free(n);
        n=NULL;
        return true;
    }
}

bool actualizar_nodo(NODO* n, item d){
    if(n!= NULL){
        n->dato = d;
        return true;
    }   
    return false;
}