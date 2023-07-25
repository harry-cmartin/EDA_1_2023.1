
#include <stdio.h>

int main(){
   
   int a;
   
   scanf("%d", &a);
   
   int vet[a];
   int vetpar[10000];
   int vetimpar[10000];
   int x = 0,y = 0;
   
   for(int i = 0;i< a;i++){
       
       scanf("%d", &vet[i]);
       if(vet[i]%2 == 0){
           vetpar[x++] = i;
           
       }else{
           
           vetimpar[y++] = i;
       }
       
   }
   
    
    
        for(int i = 0; i < x;i++){
            
            printf("%d ", vetpar[i]);
            
        }
        printf("\n");
    
        for(int i = 0; i < y;i++){
                   
           printf("%d ", vetimpar[i]);
        }
    
      
    
    return 0;
}
