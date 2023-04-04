#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 8
#define M 6

int factorial(int num){
    if(num==0) return 1;
    else return num*factorial(num-1); 
}

int calComb(int repNum, int repBus){
    int resultado, numerador, denominador;
    numerador=factorial(repNum);
    denominador=factorial(repBus)*factorial(repNum-repBus);
    resultado=numerador/denominador;
    return resultado;
}

int encontrarCombinaciones(int numero[],int busqueda[]){
    int F[M], combinaciones;
    F[0]=1;
    int repBus=1;
    int repNum=1;
    int indice=0;
    for(int i=0; i<=M; i++)
        if(busqueda[i-1]!=busqueda[i]){
            for(int j=indice;j<N;j++){
                if(numero[i]==busqueda[i-1]){
                    if(numero[i]==numero[j+1]) repNum++;
                    else{
                        indice++;
                        break;
                    }     
                }else return -1;
                indice++;
            }
            combinaciones=calComb(repNum, repBus);
            F[i]=F[i-1]*combinaciones;
            repNum=1;
            repBus=1;
        }else{
            repBus++;
            F[i]=F[i-1];
        }
    return F[M];
}

int main() {
    int numero[N]={9,5,5,3,3,3,4,6};
    int busqueda[M]={9,5,3,3,4,6};
    printf("se pueden encontrar %d variaciones", encontrarCombinaciones(numero,busqueda));
    return 0;
}

