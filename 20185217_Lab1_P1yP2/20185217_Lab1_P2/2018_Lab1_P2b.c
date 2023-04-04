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

void imprimir(int cromo[], int n){
    int i, contador;
    for(i=0; i<n; i++){
        if(cromo[i]==1) printf("%d ", i+1);
    }
    printf("\n");
}

int main(){
    printf("El ingreso de datos se realiza por consola \n");
    printf("Coloque la cadena con la forma: GOLARLAOGH, ingresando la palabra sin espacios\n");
    char cadena[11];
    scanf("%s", cadena);
    //char cadena[]={'G', 'O', 'L', 'A', 'R', 'L', 'A', 'O', 'G', 'H'};
    int n=10;
    int comb;
    int cromo[n];
    int centinela=1;
    comb=(int)pow(2,n);
    char arreglo[4];
    for(int i=0; i<comb; i++){
        cargabin(i, n, cromo);
        int p=0;
        int contador=0;
        for(int j=0;j<n;j++){
            if((cromo[j]==1) && (cadena[j]=='G'||cadena[j]=='O'||
                                 cadena[j]=='L')){                
                arreglo[p]=cadena[j];
                contador++;
                p++;
            }
            if(contador==3 && centinela==1 && cromo[j]==1){
                if((arreglo[0]=='G' && arreglo[1]=='O' && arreglo[2]=='L') || 
                    (arreglo[0]=='G' && arreglo[1]=='L' && arreglo[2]=='O') ||
                    (arreglo[0]=='O' && arreglo[1]=='G' && arreglo[2]=='L') ||
                    (arreglo[0]=='O' && arreglo[1]=='L' && arreglo[2]=='G') ||
                    (arreglo[0]=='L' && arreglo[1]=='G' && arreglo[2]=='O') ||
                    (arreglo[0]=='L' && arreglo[1]=='O' && arreglo[2]=='G')){   //Se analizan todas las posibilidades, y se imprime si cumple alguna de ellas
                    printf("la combinacion correcta es: ");
                    cargabin(i, n, cromo);
                    imprimir(cromo, n);
                    centinela=1;    //si el centinela es 0, muestra 1 solucion
                                    //si el centinela es 1, muestra todas las soluciones
                }
            }
        }
    }
    return 0;
}

