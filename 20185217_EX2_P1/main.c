#include <stdio.h>
#include <stdlib.h>

int lista[10];
int y=0, x=0;

int asigna(int i,int edades[],int tribuna,int preferencial,int vip,int n, int maxXSector,
         int total,int arrPreferencial[],int arrTribuna[],int arrVip[]){
    
    if(i==n || total<0)
        return 0;
    if(edades[i]>=45){  
        for(int j=0; j<maxXSector; j++)
            if(arrTribuna[j]==1){ 
                arrTribuna[j]=edades[i];
            }
        for(int j=0; j<maxXSector; j++)
            if(arrPreferencial[j]==1){ 
                arrPreferencial[j]=edades[i];
            }
        for(int j=0; j<maxXSector; j++)
            if(arrVip[j]==1){
                arrVip[j]=edades[i];
            }       
    }else{
        for(int j=0; j<maxXSector; j++)
            if(arrTribuna[j]==0){ 
                arrTribuna[j]=edades[i];
            }
        for(int j=0; j<maxXSector; j++)
            if(arrPreferencial[j]==0){ 
                arrPreferencial[j]=edades[i];
            }
        for(int j=0; j<maxXSector; j++)
            if(arrVip[j]==0){
                arrVip[j]=edades[i];
            }
    }	
    lista[y++]=edades[i];
    if( asigna(i+1,edades, tribuna, preferencial, vip, n, maxXSector, total-1, 
                arrPreferencial, arrTribuna, arrVip))//avanza	
            return 1;
    else{
            y--;
            return asigna(i+1,edades, tribuna, preferencial, vip, n, maxXSector, total, 
                arrPreferencial, arrTribuna, arrVip);//back
    }
}

int main() {
    int edades[]={25,50,35,28,45,23,24,18,48};
    int arrTribuna[]={0,0,0};
    int arrPreferencial[]={0,0,0};
    int arrVip[]={0,0,0};
    int maxXSector=3;
    int tribuna=2, preferencial=1, vip=0;   
    int n=sizeof(edades)/sizeof(edades[0]);
    int total=maxXSector*3;
    for(int i=0; i<3;i++){
        if(arrTribuna[i]==0 && tribuna>0){
            arrTribuna[i]=1;
            tribuna--;
        }
    }
    for(int i=0; i<3;i++){
        if(arrPreferencial[i]==0 && preferencial>0){
            arrPreferencial[i]=1;
            preferencial--;
        }
    }
    for(int i=0; i<3;i++){
        if(arrVip[i]==0 && vip>0){
            arrVip[i]=1;
            vip--;
        }
    }
    if(tribuna<=maxXSector && preferencial<maxXSector && vip<=maxXSector){
        asigna(0,edades, tribuna, preferencial, vip, n, maxXSector, total, 
                arrPreferencial, arrTribuna, arrVip);
        for(int i=0;i<maxXSector;i++)
            printf("%d ",arrTribuna[i]);
        printf("\n");
        for(int i=0;i<maxXSector;i++)
            printf("%d ",arrPreferencial[i]);
        printf("\n");
        for(int i=0;i<maxXSector;i++)
            printf("%d ",arrVip[i]);
    }
    return 0;
}

