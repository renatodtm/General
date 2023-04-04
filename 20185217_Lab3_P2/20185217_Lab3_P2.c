#include <stdio.h>
#include <stdlib.h>
#define NO_ESTA -1

void leerData(int nfilas,int ncolum,int** precios){
    for(int i=0;i<nfilas;i++) {
        precios[i] = (int*)malloc(ncolum*sizeof(int));
        for (int j=0;j<ncolum;j++) {
            scanf("%d",&precios[i][j]);
        }
    }
}
void merge(int A[],int ini,int med, int fin){
    int t1,t2,i,p,q;

    t1=med-ini+1;
    t2=fin-med;

    int P[t1+1];
    int Q[t2+1];

    for(i=ini;i<=med;i++)
        P[i-ini]=A[i];

    for(i=med+1;i<=fin;i++)
        Q[i-(med+1)]=A[i];

    P[t1]=9999999;Q[t2]=9999999;
    p=q=0;
    for(i=ini;i<=fin;i++)
        if(P[p]<Q[q])
            A[i] = P[p++];
        else
            A[i] = Q[q++];
}
void mergesort(int A[],int ini, int fin){
    if(ini==fin)
        return;
    int med = (ini+fin)/2;
    mergesort(A,ini,med);	
    mergesort(A,med+1,fin);
    merge(A,ini,med,fin);
}
int devuelveMaximoValor(int filas, int columnas, int **area){
    int maxValor=0;
    for(int i=0; i<filas; i++){
        mergesort(area[i], 0, columnas-1);
        if(area[i][columnas-1]>maxValor)
            maxValor=area[i][columnas-1];
    }
    return maxValor;
}
int recorrerIzquierda(int inicio,int final,int max,int *area){    
    if(inicio>final) 
        return -1;  
    int mid = (inicio+final)/2;
    if(area[mid] == max) 
        return mid;   
    if(area[mid]<max && area[mid+1]<area[mid]){
        return recorrerIzquierda(inicio,mid-1,max,area);
    }else{
        return recorrerIzquierda(mid+1,final,max,area);
    }
}
int recorrerDerecha(int inicio,int final,int max,int *area){    
    if(inicio>final) 
        return -1;  
    int mid = (inicio+final)/2;
    int b=area[inicio];
    int a=area[mid];
    if(area[mid] == max) 
        return mid;   
    if(area[mid]<max && area[mid-1]<area[mid]){
        return recorrerDerecha(mid+1,final,max,area);
    }else{
        return recorrerDerecha(inicio,mid-1,max,area);
    }
} 
int encuentraPosicionDelMax(int inicio, int final, int *area, int max){
    int derecha, izquierda;
    int mid=(inicio+final)/2;
    if(area[mid]==max){
        return area[mid];
    }else{
        derecha= recorrerDerecha(mid+1,final,max,area);
        izquierda= recorrerIzquierda(inicio, mid-1, max, area);
        if(izquierda!= NO_ESTA){
            return izquierda;
        }else if(derecha!= NO_ESTA){
            return derecha;
        }
    }
}
int main(){
    int filas, columnas;
    printf("Ingrese la cantidad de columas y filas: \n");
    scanf("%d %d", &columnas, &filas);
    int** area = (int **)malloc(filas*sizeof(int *));  
    int** aux = (int **)malloc(filas*sizeof(int *));  
    leerData(filas, columnas, area);
    for(int i=0;i<filas;i++) {
        aux[i] = (int*)malloc(columnas*sizeof(int));
        for (int j=0;j<columnas;j++) {
            aux[i][j]=area[i][j];
        }
    }  
    int max=devuelveMaximoValor(filas, columnas, aux);
    //hasta aqui bien
    for(int i=0;i<filas;i++){
        int posicion=encuentraPosicionDelMax(0, columnas-1, area[i], max);
        if(area[i][posicion]==max){
            printf("La potencia maxima es: %d\n", max);
            printf("La potencia maxima se encuentra en la fila: %d y la columna: %d\n",
                    i+1, posicion+1);
            break;
        }
    }
    return 0;
}

