#include "Colacircular.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Funcion que crea la Cola Circular
 * 
 * @return CCircular* 
 */
CCircular* crear_cola(){
    CCircular *c = (CCircular*)malloc(sizeof(CCircular));
    c->longitud = 0;
    c->primero = c->ultimo = NULL;
    return c;
}

/**
 * @brief Funcion que Borra la Cola
 * 
 * @param c Cola Circular
 * @return true SI se pudo borrar la Cola
 * @return false Si no se pudo borrar
 */
bool borrar_cola(CCircular*c){
    if(c!=NULL){
        if(!es_vacia(c)){
            vaciar(c);
        }
        free(c);
        return true;
    }
    return false;
}

/**
 * @brief Funcion que vacer la Cola
 * 
 * @param c Cola Circular
 * @return true Si se pudo vacear
 * @return false Si no se pudo vacear
 */

bool vaciar(CCircular*c){
    while (c->longitud>0)
    {
        desencolar(c);
    }

    return es_vacia(c);
}

/**
 * @brief Funcion que verifica si la Cola es vacia
 * 
 * @param c Cola Circular
 * @return true Si es vacia
 * @return false Si no es vacia
 */

bool es_vacia(CCircular*c){
    return (c->longitud==0)? true: false;
}

/**
 * @brief Funcion que regresa el primero de la Cola
 * 
 * @param c Cola Circular
 * @return item primer dato de la Cola
 */

item primero(CCircular*c){
    return c->primero;
}

/**
 * @brief Funcion que agrega datos
 * 
 * @param c Cola Circular
 * @param dato dato dado por el usuario 
 * @return true Si se pudo encolar
 * @return false Si no se pudo encolar
 */

bool encolar(CCircular* c, item dato){
    if (es_vacia(c))
    {
        NODO *nuevo = crear_nodo(dato);
        nuevo->siguiente = c->primero;
        c->primero = c->ultimo = nuevo;
        c->longitud++;
        return true;
    }else if(c->primero == c->ultimo){
        NODO *nuevo = crear_nodo(dato);
        c->primero->siguiente = nuevo;
        c->ultimo = nuevo;
        c->longitud++;
        return true;
    }else{
        NODO *nuevo = crear_nodo(dato);
        c->ultimo->siguiente = nuevo;
        c->ultimo = nuevo;
        c->longitud++;
        return true;
    }
    return false;
}

/**
 * @brief Funcion que desencola elemntos de la Cola
 * 
 * @param c Cola Circular
 * @return true Si se pudo desencolar
 * @return false si no se pudo desencolar
 */

bool desencolar(CCircular* c){
    if (!es_vacia(c))
    {
        NODO *tmp;
        tmp = c->primero;
        c->primero = c->primero->siguiente;
        free(tmp);
        tmp = NULL;
        c->longitud--;
        return true;
    }
    return false;
}

/**
 * @brief Funcion que Imprime la Cola
 * 
 * @param c Cola Circular
 */

void imprimir(CCircular *c){
    printf("[ ");
    for(NODO *tmp=c->primero; tmp!=NULL; tmp =tmp->siguiente){
        printf("%d ", tmp->dato);
    }
    printf("]\n");
}


