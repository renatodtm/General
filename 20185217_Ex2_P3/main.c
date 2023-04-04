#include <stdio.h>
#include <stdlib.h>
//P3a

void swap(int* value1, int* value2){
    int temp= *value1;
    *value1=*value2;
    *value2=temp;
}

void bubbleSort(int arraySize, int myArray[]){
    for(int i=0;i<(arraySize-1); i++){
        for(int j=i+1; j<arraySize;j++){
            if(myArray[j]<myArray[i]){
                swap(&myArray[i],&myArray[j]);  
            }                
        } 
    }
}

int buscapresupuesto(int arr[],int n,int sum){
	int F[n+1][sum+1];	
	for(int i=0;i<=n;i++)
		F[i][0]=1;		
	for(int i=1;i<=sum;i++)
		F[0][i]=0;	
	for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                F[i][j]=F[i-1][j];
                if(j-arr[i-1]>=0 && F[i][j]==0)
                        F[i][j]=F[i-1][j-arr[i-1]];
            }
	}
	for(int i=sum;i>0;i--)	
            if(F[n][i]==1) return i;	
}



int main(){
        int n=5;
	int tareas[5]={1,3,6,10,16};
        bubbleSort(n,tareas);	
        int desperdicio[3];
        desperdicio[0]=8-buscapresupuesto(tareas,n,8);
	desperdicio[1]=16-buscapresupuesto(tareas,n,16);
        desperdicio[2]=24-buscapresupuesto(tareas,n,24);	
        printf("%d ", desperdicio[1]);
	return 0;
}
