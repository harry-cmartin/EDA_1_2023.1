
#include <stdio.h>

int main(){
   
   int ent,linha = 0;
   
   scanf("%d", &ent);
   
   for(int i = 0;i < ent;i++){
       linha++;
       if(linha%2 == 0){
           printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
           
       }else{
           printf("THUMS THUMS THUMS\n");
           
       }
       
       
   }

    return 0;
}
