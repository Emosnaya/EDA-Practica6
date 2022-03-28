#include "ColaDoble.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Funcion que crea la cola Doble
 * 
 * @return CDoble* 
 */

CDoble* crear_cola(){
    CDoble *c = (CDoble*)malloc(sizeof(CDoble));
    c->longitud = 0;
    c->primero = c->ultimo = NULL;
    return c;
}

/**
 * @brief Funcion que Borra la Cola
 * 
 * @param c Cola
 * @return true si se pudo borrar
 * @return false Si no se pudo borrar
 */
bool borrar_cola(CDoble*c){
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
 * @brief Funcion que vacea la Cola
 * 
 * @param c Cola Doble
 * @return true Si se pudo vacear
 * @return false Si no se pudo vacear
 */
bool vaciar(CDoble*c){
    while (c->longitud>0)
    {
        desencolar_inicio(c);
    }

    return es_vacia(c);
}

/**
 * @brief Funcion que verifica si está vacia la Cola 
 * 
 * @param c Cola Doble
 * @return true Si está vacia la COla
 * @return false SI no está vacia la Cola
 */
bool es_vacia(CDoble*c){
    return (c->longitud==0)? true: false;
}

/**
 * @brief Funcion retorna el primer elemento de la Cola
 * 
 * @param c ColaDoble
 * @return item Primer Dato de la Cola
 */

item primero(CDoble*c){
    return c->primero->dato;
}

/**
 * @brief Funcion que imprime la Cola
 * 
 * @param c ColaDoble
 */
void imprimir(CDoble*c){
    printf("[ ");
    for(NODO *tmp=c->primero; tmp!=NULL; tmp =tmp->siguiente){
        printf("%d ", tmp->dato);
    }
    printf("]\n");
}

/**
 * @brief Funcion que Encola al inicio
 * 
 * @param c ColaDoble
 * @param dato Dato dado por el usuario 
 * @return true SI se pudo encolar
 * @return false Si no se pudo encolar
 */
bool encolar_incio(CDoble*c, item dato){
    NODO *nuevo = crear_nodo(dato);
    nuevo->siguiente = c->primero;
    c->primero = c->ultimo = nuevo;
    c->longitud++;
    return true;
}

/**
 * @brief Funcion que desencola al inicio
 * 
 * @param c ColaDoble
 * @return true Si se pudo desencolar
 * @return false si no se pudo desencolar
 */
bool desencolar_inicio(CDoble*c){
    if(!es_vacia(c)){
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
 * @brief Funcion que Encola al final
 * 
 * @param c Cola Doble
 * @param d Dato ingresado por el usuario
 * @return true SI se puedo encolar
 * @return false Si no se pudo encolar
 */
bool encolar_fin(CDoble* c, item d){
    NODO *nuevo = crear_nodo(d);
    c->ultimo->siguiente = nuevo;
    c->ultimo = nuevo;
    c->longitud++;
    return true;
}

/**
 * @brief Funcion que desencola al final
 * 
 * @param c Cola Doble
 * @return true Si se pudo desecnolar
 * @return false Si no se pudo desenecolar
 */
bool desencolar_fin(CDoble*c){
    if(!es_vacia(c)){
        NODO *tmp;
        tmp = c->ultimo;
        c->ultimo = c->ultimo->siguiente;
        free(tmp);
        tmp = NULL;
        c->longitud--;
        return true;
    }
    return false;
}