#ifndef ABB_H
#define ABB_H

typedef struct{
    int binario;
    int peso;
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
void insertar( ArbolBinarioBusqueda *pABB, int peso );

#endif


