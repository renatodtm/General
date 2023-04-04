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
void recorrerEnOrden(ArbolBinario AB){
    ArbolBinario ABI, ABD;
    if ( !esArbolVacio(AB) )
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        recorrerEnOrden(ABI);
        printf("(%d-%d) ", AB->elemento.lote, AB->elemento.stock);
        recorrerEnOrden(ABD);
    }
}
void recorrerEnPreorden ( ArbolBinario AB ){
    ArbolBinario ABI, ABD;
    if ( !esArbolVacio(AB) )
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        printf("(%d-%d) ", AB->elemento.lote, AB->elemento.stock); // raiz
        recorrerEnPreorden(ABI);
        recorrerEnPreorden(ABD);
    }
}
int contarNodosEnArbol( ArbolBinario AB ){   
    ArbolBinario ABI, ABD;
    int nodosABI, nodosABD;
    if ( esArbolVacio(AB) )
        return 0;
    else
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        nodosABI = contarNodosEnArbol( ABI );
        nodosABD = contarNodosEnArbol( ABD );
        return nodosABI + nodosABD + 1;
    }
}
void insertarEnABB( ArbolBinarioBusqueda *pABB, Elemento elemento ){ //SE TIENE QUE MODIFICAR
    NodoArbol *p, *padre;
    if ( esArbolVacio(*pABB) )
        plantar(pABB,NULL,elemento,NULL);
    else
    {
        padre = NULL;
        p = *pABB;
        while ( p != NULL )
        {
            padre = p;
            if (elemento.lote< p->elemento.lote)   //cambia aqui
                p = p->hizq;
            else
                p = p->hder;
        }
        if ( elemento.lote < padre->elemento.lote) //cambia aqui
            plantar(&(padre->hizq), NULL,elemento,NULL);
        else
            plantar(&(padre->hder), NULL, elemento,NULL);
    }    
}
