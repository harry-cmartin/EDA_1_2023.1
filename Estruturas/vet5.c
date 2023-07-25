
#include <stdio.h>

int main(){
   
   int a,b;
   scanf("%d", &a);
   int vet[a], achou =0;
   
   for(int i = 0;i< a;i++){
       scanf("%d", &vet[i]);
       
   }
   scanf("%d",&b);
   
   for(int i = 0; i <a; i++){
       if(vet[i] == b){
           achou = 1;
       }
       
   }
   
   if(achou == 1){
       printf("pertence");
       
   }else{
       
       printf("nao pertence");
   }
  
    
    return 0;
}
