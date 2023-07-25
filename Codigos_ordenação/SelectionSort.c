

#include <stdio.h>

typedef int item;

#define Key(A) (A)
#define less(A,B) ( Key(A) < Key (B))
#define exchange(A,B) {item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exchange(A,B);)}

void selectionsort(item *v,int l, int r){

    if(l == r) return;
    
    int min = l;
    
    for(int j = l+1; j <= r; j++){
        
        if(less(v[j], v[min])){
            min = j;
            
        }
        
    }
    
    exchange(v[min], v[l]);
    selectionsort(v,l+1,r);

}


int main()
{
    int g[10] = {8,4,3,8,1,7,8,3,6,9};
    
    
    
    selectionsort(g,0,9);

    for(int y = 0; y < 10;y++){
        
        printf("%d ", g[y]);
    }

    return 0;
}








