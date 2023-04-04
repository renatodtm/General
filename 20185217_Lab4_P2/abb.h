#ifndef ABB_H
#define ABB_H

typedef struct{
    int lote;
    int stock;
}Elemento;

typedef struct nodoABB {   
    struct nodoABB *hizq;
    Elemento elemento;
    struct nodoABB *hder;
} NodoArbol;
typedef NodoArbol* ArbolBinario;
typedef ArbolBinario ArbolBinarioBusqueda;
void construirArbol(ArbolBinario *pAB);
int esArbolVacio(ArbolBinario AB);
NodoArbol *crearNuevoNodoArbol(ArbolBinario arbolIzq, Elemento elemento, ArbolBinario arbolDer);
void plantar( ArbolBinario *pAB, ArbolBinario arbolIzq, Elemento elemento, ArbolBinario arbolDer );
void recorrerEnOrden(ArbolBinario AB);
void recorrerEnPreorden ( ArbolBinario AB );
int contarNodosEnArbol( ArbolBinario AB );
void insertarEnABB( ArbolBinarioBusqueda *pABB, Elemento elemento );

#endif



