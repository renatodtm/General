#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hora;
    int sucursal;
    char dia;
}Elemento;
typedef struct nodo{
    Elemento elemento;
    struct nodo *sig;
}Nodo;
typedef struct{
    Nodo *cabeza;
}Lista;
void construirLista( Lista *pL ){
    pL->cabeza = NULL;
}
int esListaVacia( Lista L ){
    return L.cabeza == NULL;
}
Nodo* crearNuevoNodo( Elemento elemento, Nodo *sig ){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}
Nodo* obtenerUltimoNodo( Lista L ){
    Nodo *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = L.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}
Nodo* obtenerNodoAnterior( Lista L, int hora){
    Nodo *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = L.cabeza;
    while ( pNodo != NULL ){
        if ( pNodo->elemento.hora == hora )
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}
void mostrar( Lista L ){
    Nodo *pNodo;
    if ( esListaVacia( L) )
        printf("La lista esta vacia\n");
    else{
        pNodo = L.cabeza;
        while ( pNodo != NULL ){
            printf("(%d)(%d)%c ->", pNodo->elemento.hora, pNodo->elemento.sucursal, pNodo->elemento.dia);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}
void insertar_en_orden(Lista *pL, Elemento elemento){
    Nodo *pNuevoNodo=crearNuevoNodo(elemento, NULL);
    Nodo *nodoAnterior=obtenerNodoAnterior(*pL, elemento.hora);
    if (nodoAnterior==NULL){
        pNuevoNodo->sig=pL->cabeza;
        pL->cabeza=pNuevoNodo;
    }
    else{
        pNuevoNodo->sig=nodoAnterior->sig;
        nodoAnterior->sig=pNuevoNodo;
    }
}
void inserta(Lista *pL, int hora, int sucursal, char dia){
    Elemento elemento;
    elemento.dia=dia;
    elemento.hora=hora;
    elemento.sucursal=sucursal;
    insertar_en_orden(pL, elemento);
}

void leerDatos(Lista *pL, char dia){
    int hora=0, sucursal=0;
    printf("ingresar datos del dia %c \n", dia);
    while(hora!=-1 && sucursal != -1){
        scanf("%d %d", &hora, &sucursal);
        inserta(pL,hora,sucursal,dia);
    }
}

void unir(Lista *destino, Lista *inicio){
    Nodo *ultNodo, *dest, *pNodo;
    ultNodo=obtenerUltimoNodo(*destino);
    dest= destino->cabeza;
    if(ultNodo==NULL){
        destino->cabeza= inicio->cabeza;
        inicio->cabeza = NULL;
    }else if(ultNodo->elemento.hora<dest->elemento.hora){
        ultNodo->sig = inicio->cabeza;
        inicio->cabeza= NULL;
    }else{
        pNodo = destino->cabeza;
        while(inicio->cabeza!=NULL){
            if(pNodo->sig!=NULL){
                if(pNodo->sig->elemento.hora >inicio->cabeza->elemento.hora){
                    Nodo* tempNodo = pNodo->sig;
                    pNodo->sig = inicio->cabeza;
                    inicio->cabeza = inicio->cabeza->sig;
                    pNodo->sig->sig = tempNodo;
                }          
                pNodo = pNodo->sig;
            }else{
                pNodo->sig = inicio->cabeza;
                inicio->cabeza = NULL;
            }
        }
    }
}

int main() {
    Lista lunes, martes, miercoles, jueves, viernes;
    int hora, sucursal, i=0;
    construirLista(&lunes);
    construirLista(&martes);
    construirLista(&miercoles);
    construirLista(&jueves);
    construirLista(&viernes);
    leerDatos(&lunes,'L');
    leerDatos(&martes,'M');
    leerDatos(&miercoles,'N');
    leerDatos(&jueves,'J');
    leerDatos(&viernes,'V');
    mostrar(lunes);
    mostrar(martes);
    mostrar(miercoles);
    mostrar(jueves);
    mostrar(viernes);
    unir(&lunes,&martes);
    unir(&lunes,&miercoles);
    unir(&lunes,&jueves);
    unir(&lunes,&viernes);
    mostrar(lunes);
    return 0;
}

