
#include <stdio.h>

int main(){
    
    int vet[5];
    
    for(int i = 0; i < 5; i++){
        scanf("%d", &vet[i]);
    }
    
    int maior = 0, menor = 0;
    for(int i = 0; i < 4; i++){
        
        if(vet[i+1] > vet[i]){
            maior++;
        }
        
        if(vet[i+1] < vet[i]){
            menor++;
  
        }
        
    }
    
    if(maior == 4){
        printf("C\n");
        
    }else if(menor == 4){
        printf("D\n");
        
    }else{
        printf("N\n");
        
    }
    
    return 0;
}
