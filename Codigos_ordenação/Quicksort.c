#include <stdio.h>

void troca(int *a, int*b){
    
    int tmp = *a;
    *a = *b;
    *b =tmp;
    
}

int particiona(int * v,int e, int d){
    
    int p =v[d];
    int k =e, j =e;
    
    while(k < d){
        
        if(v[k] <= p){
            troca(&v[k], &v[j]);
            j++;
            
        }
        k++;
    }
    
    troca(&v[k], &v[j]);
    return j;
}


void quicksort(int *v, int e,int d){
    
    if(e < d){
        
        int j = particiona(v,e,d);
        quicksort(v,e,j-1);
        quicksort(v,j+1,d);
        
    }
    
    
}



int main()
{
    int vetor[10] = {6,9,3,3,4,1,0,8,4,5};
    
    quicksort(vetor,0,9);
    
    for(int i = 0;i < 10;i++){
        
        printf("%d ", vetor[i]);
    }

    return 0;
}