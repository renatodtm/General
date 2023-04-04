#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main() {    
    ArbolBinarioBusqueda abb1;
    construirArbol(&abb1);
    int cantidad, peso, pesoBuscado;
    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d",&cantidad); 
    int arregloPesos[cantidad];
    insertar(&abb1,peso);  
    printf("Ingresa los pesos del arreglo:\n");
    for(int i=0; i<cantidad;i++){
       scanf("%d",peso);
       arregloPesos[i]=peso;
       insertar(&abb1,arregloPesos[i]);
    }
    printf("ingrese el peso que desea buscar: \n");
    scanf("%d", &pesoBuscado);
    return 0;
}

