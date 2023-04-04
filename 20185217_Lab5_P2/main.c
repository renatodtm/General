#include <stdio.h>
#include <stdlib.h>
#define MAX_MOV 4
#define MAX_INI 8
#define maxN 20 
#define maxM 20

int map[MAX_MOV][2];
int mov[MAX_INI][2];
int totalRectangulos=0;
void generaMovimientos(int largo);
void generaPosicion();
void generarNuevaTabla(int tabla[maxN][maxM], int n,int m);
void imprimirTabla(int tabla[maxN][maxM], int n,int m);
int esValido(int a[maxN][maxM], int x, int y, int n,int m);
void marca(int a[maxN][maxM],int x1,int y1,int x2,int y2,int n,int m,int nMov);
int validaRecorrido(int a[maxN][maxM],int x1,int y1,int x2,int y2,int n,int m);
int encuentraCamino(int tablaVacia[maxN][maxM],int n,int m,int x,int y,int nMov,int solu[maxN][maxM], int c);


int main(){    
    int n,m,c;
    printf("Ingrese las dimensiones n y m del tablero: \n");
    scanf("%d %d", &n, &m);
    printf("Ingrese el largo (c) de los rectangulos entre 1 y 5:\n");
    scanf("%d", &c);
    int tabla[maxN][maxM];
    int solucion[maxN][maxM];
    generarNuevaTabla(tabla, n, m);       
    encuentraCamino(tabla, n, m,  -1, 0, 1,solucion, c-1);
    printf("\nTotal de rectangulos = %d\n",totalRectangulos);
    imprimirTabla(solucion ,n, m);
    return 0;
}

void generaMovimientos(int largo){
    map[0][0] =  largo; map[0][1] =  0;
    map[1][0] =  0; map[1][1] = -1*largo;
    map[2][0] =  0; map[2][1] =  largo;
    map[3][0] = -1*largo; map[3][1] =  0;
}
void generaPosicion(){
    mov[0][0] =  1; mov[0][1] =  0;
    mov[1][0] =  0; mov[1][1] = -1;
    mov[2][0] =  0; mov[2][1] =  1;
    mov[3][0] = -1; mov[3][1] =  0;   
    mov[4][0] =  1; mov[4][1] =  1;
    mov[5][0] = -1; mov[5][1] = -1;
    mov[6][0] =  1; mov[6][1] = -1;
    mov[7][0] = -1; mov[7][1] =  1;
}
void generarNuevaTabla(int tabla[maxN][maxM], int n,int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tabla[i][j] = 0;
}
void imprimirTabla(int tabla[maxN][maxM], int n,int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d\t", tabla[i][j]);
        printf("\n");
    }
}
int esValido(int a[maxN][maxM], int x, int y, int n,int m) {
    if ( x < n && y < m && x >= 0 && y >= 0 && a[x][y] == 0)  
        return 1;
    return 0;
}
int validaRecorrido(int a[maxN][maxM],int x1,int y1,int x2,int y2,int n,int m){
    if(esValido(a,x2,y2,n,m)){
        if(x1<x2)
            for(int j=x1;j<=x2;j++){
                if(a[j][y1]!=0) return 0;
            }    
        else
            for(int j=x1;j>=x2;j--)
                if(a[j][y1]!=0) return 0;
        if(y1<y2)
            for(int k=y1;k<=y2;k++){
                if(a[x1][k]!=0) return 0;
            }    
        else
            for(int k=y1;k>=y2;k--)
                if(a[x1][k]!=0) return 0;    
        return 1;
    }
    return 0;
}
void marca(int a[maxN][maxM],int x1,int y1,int x2,int y2,int n,int m,int nMov){
    int j,k;
    
    if(x1<x2)
        for(j=x1;j<=x2;j++)
            a[j][y1] = nMov;
    else
	for(j=x1;j>=x2;j--)
            a[j][y1] = nMov;
    if(y1<y2)
        for(k=y1;k<=y2;k++)
            a[x1][k] = nMov;
    else
        for(k=y1;k>=y2;k--)
            a[x1][k] = nMov;
}
int encuentraCamino(int tablaVacia[maxN][maxM],int n,int m,int x,int y,int nMov,int solu[maxN][maxM], int c){
    int new_x,new_y,mov_x,mov_y;
    generaMovimientos(c); 
    generaPosicion();   
    if(nMov == n*m) return 1;       
    for(int i = 0; i<MAX_INI; i++ ) { 
        new_x = x + mov[i][0];
        new_y = y + mov[i][1];        
        if(esValido(tablaVacia,new_x,new_y,n,m)){
            for(int j = 0; j<MAX_MOV; j++){
                mov_x = new_x + map[j][0];
                mov_y = new_y + map[j][1];
                if(validaRecorrido(tablaVacia,new_x,new_y,mov_x,mov_y,n,m)){
                    marca(tablaVacia,new_x,new_y,mov_x,mov_y,n,m,nMov);
                    if(nMov>totalRectangulos){
                        totalRectangulos = nMov;
                        generarNuevaTabla(solu,n,m);
                        for(int p = 0; p < n; p++ )
                            for(int q = 0; q < m; q++ )
                                solu[p][q] =tablaVacia[p][q];
                    }
                    if(encuentraCamino(tablaVacia,n,m,mov_x,mov_y,nMov+1,solu, c))
                        return 1;
                    marca(tablaVacia,new_x,new_y,mov_x,mov_y,n,m,0);
                }
            } 
        }
    }
    return 0;
}

