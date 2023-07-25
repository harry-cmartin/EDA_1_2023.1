

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exchange(A,B) {item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exchange(A,B);}


void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(less(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m){
      R[k++]=V[i++];
  }  
  while(j<=r){
      R[k++]=V[j++];
  }

  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
  
}


int main()
{
    int vetor[10] = {6,9,3,3,4,1,0,8,4};
    
    mergesort(vetor,0,9);
    
    for(int i = 0;i < 10;i++){
        
        printf("%d ", vetor[i]);
    }

    return 0;
}



