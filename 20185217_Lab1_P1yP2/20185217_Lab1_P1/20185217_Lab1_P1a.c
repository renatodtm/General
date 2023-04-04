#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cargabin(int num, int n, int cromo[]){
    int res, i;
    for(i=0; i<n; i++){
            cromo[i]=0;
    }
    i=0;
    while(num>0){
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

void imprimirHerramientas(int cromo[], int n){
	int i;
    for(i=0; i<n; i++){
        if(cromo[i]==1) printf("%d ", i+1);
    }
    printf("\n");
}
/*
 *  Esta renovando y quiere algunas nuevas
 *  Maximo 4 tipos de herramientas a elegir
 *  
 */
int P=19;
int M=4;

int main() {
    int n=8;
    int pxH[]={4,5,4,2,6,3,4,1};
    int cantidad[]={3,2,1,1,3,3,2,4};
    int comb=(int)pow(2,n);
    int cromo[n];
    for(int i=0; i<comb; i++){//recorremos todas las posibilidades del cromo
        cargabin(i, n, cromo);
        int contador=0;//contara cuantas herramientas se acumulan, debe ser menor o igual a 4
        int precioxCant=0;  //acumulara el precioxcantidad
        int cantidadHerramientas=0; //acumula la cantidad de herramientas
        for(int j=0; j<n; j++){ //analizamos el cromo
            if(cromo[j]==1){
                precioxCant += (int)pxH[j]*(int)cantidad[j];
                cantidadHerramientas += cantidad[j];
                contador++;               
            }
            if(contador==M && precioxCant==P){
                cargabin(i, n, cromo);
                printf("Herramientas: ");
                imprimirHerramientas(cromo, n);
                printf("Monto Total: %d\n", precioxCant);
                printf("cantidad de herramientas: %d\n", cantidadHerramientas);
            }
        }
    }  
    return 0;
}

