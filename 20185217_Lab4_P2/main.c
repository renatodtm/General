#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

/*Ejemplo para ingreso de datos
20170810 20
20170620 20
20180409 10
20180211 20
-1 -1
20170811 5
20180211 10
20180410 15
-1 -1
 */

void leerDatos(int numArbol, ArbolBinarioBusqueda *pABB){
    int lote, stock;
    Elemento elemento;
    printf("Insertar lote y stock para el arbol %d. Ingrese -1 -1 para terminar.\n",numArbol);
    while(1){        
        scanf("%d %d",&lote,&stock);
        if ((lote==-1)||(stock==-1)) {
            break;
        }
        elemento.lote= lote;
        elemento.stock= stock;
        insertarEnABB(pABB,elemento);
    }
}
void insertaLotes(ArbolBinarioBusqueda *ABB,NodoArbol *nodoAux) {
    if (esArbolVacio(*ABB)){
	*ABB = nodoAux;
        return;
    }
    if ((*ABB)->elemento.lote==nodoAux->elemento.lote) {
        (*ABB)->elemento.stock += nodoAux->elemento.stock;
    } else if ((*ABB)->elemento.lote>nodoAux->elemento.lote) {
        insertaLotes(&(*ABB)->hizq,nodoAux);
    } else {
        insertaLotes(&(*ABB)->hder,nodoAux);
    }        
}

void mezclar(ArbolBinarioBusqueda *emisor, ArbolBinarioBusqueda *destino) {
    if (esArbolVacio(*emisor)) {
        return;
    }
    if(!esArbolVacio((*emisor)->hizq)) {
        mezclar(&(*emisor)->hizq,destino);
    }
    if(!esArbolVacio((*emisor)->hder)) {
        mezclar(&(*emisor)->hder,destino);
    }
    insertaLotes(destino,*emisor);
    *emisor = NULL;
}

int main(){
    ArbolBinarioBusqueda abb1, abb2;
    construirArbol(&abb1);
    construirArbol(&abb2);
    leerDatos(1, &abb1);
    leerDatos(2, &abb2);
    printf("Arbol 1:\n");
    printf("en orden ");
    recorrerEnOrden(abb1);
    printf("\n");
    printf("en preorden ");
    recorrerEnPreorden(abb1);
    printf("\n");
    printf("Arbol 2:\n");
    printf("en orden ");
    recorrerEnOrden(abb2);
    printf("\n");
    printf("en preorden ");
    recorrerEnPreorden(abb2);
    printf("\n");
    if(contarNodosEnArbol(abb1)>contarNodosEnArbol(abb2)){
        printf("\nEl arbol 1 sera el destino\n");
        mezclar(&abb2,&abb1);
        printf("El arbol final en orden:\n");
        recorrerEnOrden(abb1);
        printf("\n");
        printf("El arbol final en preorden:\n");
        recorrerEnPreorden(abb1);
        printf("\n");
    } else {
        printf("\nEl arbol 2 sera el destino\n");
        mezclar(&abb1,&abb2);
        printf("El arbol final en orden:\n");
        recorrerEnOrden(abb2);
        printf("\n");
        printf("El arbol final en preorden:\n");
        recorrerEnPreorden(abb2);
        printf("\n");
    }
    
    return 0;
}

