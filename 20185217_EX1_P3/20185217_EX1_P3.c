#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Elemento;

typedef struct nodo{
    Elemento elemento;
    struct nodo *sig;
} Nodo;

typedef struct lista{
    Nodo *cabeza;   
} Lista;

typedef struct cola{
    Nodo *cabeza;
    Nodo *final;
    int longitud;
} Cola;
void construirCola( Cola *pC ){
    pC->cabeza = NULL;
    pC->final = NULL;
    pC->longitud = 0;
}
int esColaVacia( Cola C ){
    return C.cabeza == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}
void construirLista( Lista *pL ){
    pL->cabeza = NULL;
}
int esListaVacia( Lista L ){
    return L.cabeza == NULL;
}
Nodo* crearNuevoNodoLista( Elemento elemento, Nodo *sig ){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}
Nodo* crearNuevoNodoCola( Elemento elemento )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = NULL;
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
void insertarFinal(Lista *pL, Elemento elemento ){
    Nodo *pNuevoNodo, *pUltimo;
    pNuevoNodo = crearNuevoNodoLista( elemento, NULL);
    pUltimo = obtenerUltimoNodo(*pL);
    if ( pUltimo == NULL )
        pL->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}
void encolar( Cola *pC, Elemento elemento ){
    Nodo *pNuevoNodo, *pFinal;
    pNuevoNodo = crearNuevoNodoCola( elemento );
    if ( esColaVacia( *pC ) )
        pC->cabeza = pNuevoNodo;
    else
    {
        pFinal = pC->final;
        pFinal->sig = pNuevoNodo;
    }
    pC->final = pNuevoNodo;
    pC->longitud++;
}
void mostrarLista( Lista L ){
    Nodo *pNodo;
    if ( esListaVacia( L) )
        printf("La lista esta vacia\n");
    else{
        pNodo = L.cabeza;
        while ( pNodo != NULL ){
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}
int buscar(Cola *C, Elemento valor ){
    Nodo *pNodo;
    pNodo = C->cabeza;
    while ( pNodo != NULL ){
        if (valor==pNodo->elemento)
            return 1;
        pNodo = pNodo->sig;    
    }
    return 0;
}
void mostrarCola( Cola *C ){
    Nodo *pNodo;
    if ( esColaVacia( *C ) )
        printf("La cola esta vacia\n");
    else
    {
        pNodo = C->cabeza;
        while ( pNodo != NULL )
        {
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

void procesarNumeros(int i,int multiplicador,int encontrado,int n,Lista *lista1,Cola *eliminados){   
    Nodo *pNodo;    
    if(encontrado!=1){        
        if(i*multiplicador<=n && pow(i,2)<=n){
            if(multiplicador==1){
                printf("Numero Procesado: %d\n", i);
                printf("Numeros tachados para el %d: ",i);
            }                
            encontrado=buscar(eliminados, i*multiplicador);
            encolar(eliminados, i*multiplicador);           
            procesarNumeros(i,multiplicador+1,encontrado,n,lista1,eliminados);           
        }
        
    }else{
        printf("\nNumero Procesado: %d\n", i);
        printf("%d no tiene numeros tachados", i);
        encontrado=0;
    }
    if(multiplicador==1)
        mostrarCola(eliminados);      
}

int main(){
    Lista lista1;
    Cola eliminados;
    construirLista(&lista1);
    construirCola(&eliminados);
    int n;
    printf("Ingrese a el tope: \n");
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        insertarFinal(&lista1, i);   
    }
    printf("Lista llena: ");
    mostrarLista(lista1);
    printf("------------------------------------\n");
    printf("Pasamos a proceso: \n");
    for(int i=2; i<=n;i++){
        procesarNumeros(i,1,0,n, &lista1, &eliminados);
    }   
    return 0;
}

