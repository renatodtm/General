#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void construirArbol(ArbolBinario *pAB){
    *pAB = NULL;
}
int esArbolVacio(ArbolBinario AB){
    return AB == NULL;
}
NodoArbol *crearNuevoNodoArbol(ArbolBinario arbolIzq, Elemento elemento, ArbolBinario arbolDer){
    NodoArbol *pNuevoNodo;
    pNuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    pNuevoNodo->hizq = arbolIzq;
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->hder = arbolDer;
    return pNuevoNodo;
}
void plantar( ArbolBinario *pAB, ArbolBinario arbolIzq, Elemento elemento, ArbolBinario arbolDer ){
    NodoArbol *pNuevoNodo;
    pNuevoNodo = crearNuevoNodoArbol( arbolIzq, elemento, arbolDer );
    *pAB = pNuevoNodo;
}
void insertar( ArbolBinarioBusqueda *pABB, int peso ){ 
    Elemento elemento;
    NodoArbol *padre;
    if ( esArbolVacio(*pABB) ){
        elemento.binario=0;
        elemento.peso=0;
        plantar(pABB,NULL,elemento,NULL);
    }
    else{
        padre = *pABB;
        if( (*pABB)->hizq==NULL && (*pABB)->hder==NULL ){
            elemento.peso=peso;
            elemento.binario=0;
            plantar(&(padre->hizq),NULL,elemento,NULL);
            elemento.binario=1;
            plantar(&(padre->hder),NULL,elemento,NULL);                    
        }else{
            insertar(&(padre->hizq),peso);
            insertar(&(padre->hder),peso);
        }
    }    
}