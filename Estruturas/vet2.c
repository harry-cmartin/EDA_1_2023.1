
#include <stdio.h>

int main(){
   
   int a,zero = 0;
   
   scanf("%d", &a);
   
   int vet[a];
   
   for(int i = 0;i < a; i++){
       
       scanf("%d",&vet[i]);
       
        if(vet[i] < vet[zero]){
            zero = i;
        }
        
   }

    printf("%d", zero);
    
    return 0;
}
