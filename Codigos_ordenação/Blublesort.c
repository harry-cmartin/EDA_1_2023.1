

#include <stdio.h>
typedef int item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exchange(A,B) {item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exchange(A,B);}

void buble(item *v, int l , int r){
    
    for(int i = l ; i < r; i++){
        for (int j = l ;j < r;j++){
            cmpexch(v[j], v[j+1]);
            
        } 
        
        
    }
    
    
}

int main()
{
    int vetor[10] = {9,4,7,2,9,6,7,2,9,5};
    
    buble(vetor,0,9);
    
    for(int y = 0; y < 10;y++){
        printf("%d ", vetor[y]);
    }
    
    return 0;
}

