#include <stdio.h>
#include <stdlib.h>

int encuentraPesoMaximo(int n,int k,int lista[]){
    int max=0;
    int F[n];
    for(int i=0; i<n;i++)
        F[i]=0;
    F[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<i; j++){
            if(abs(lista[i]-lista[j])<k){
                if(lista[i]+lista[j]>F[j])
                    F[i] = lista[i]+lista[j];
                else
                    F[i]=F[j];
            }
        }if(F[i]>max) max=F[i];
    }
    return max;
}

int main() {
    int k, n;   
    printf("ingrese la cantidad de datos del arreglo:\n");
    scanf("%d", &n);
    int lista[n];
    printf("ingrese %d datos para el arreglo:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &lista[i]);
    }
    printf("ingrese la maxima diferencia k:\n");
    scanf("%d", &k);
    int maximo=encuentraPesoMaximo(n,k,lista);     
    printf("El peso maximo es: %d\n", maximo);

    return 0;
}

