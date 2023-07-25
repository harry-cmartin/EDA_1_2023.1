

#include <stdio.h>
typedef int item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exchange(A,B) {item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exchange(A,B);}


void insertionsort(item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-1],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; item tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}

int main()
{
    int vetor[8] = {8,15,5,9,12,48,0};
    
    insertionsort(vetor,0,7);
    for(int i = 0; i < 8;i++){
        printf("%d ", vetor[i]);
        
    }
    
    return 0;
}
