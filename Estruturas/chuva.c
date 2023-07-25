
#include <stdio.h>

int main()
{
    int entra;
    
    scanf("%d", &entra);
    
    int vet[entra][entra];
    int vet2[entra][entra];
    int mapa_soma[entra][entra];
    
    
    for(int i = 0; i < entra;i++){
        for(int j = 0;j < entra; j++){
            scanf("%d", &vet[i][j]);
            
            
        }
        
    }
    
    
     for(int i = 0; i < entra;i++){
        for(int j = 0;j < entra; j++){
            scanf("%d", &vet2[i][j]);
            
            
        }
        
    }
    
    for(int i = 0; i < entra;i++){
        for(int j = 0;j < entra; j++){
            mapa_soma[i][j] = vet[i][j] + vet2[i][j];
            
            
        }
        
    }
    
    for (int i = 0; i < entra; i++) {
        for (int j = 0; j < entra; j++) {
            printf("%d ", mapa_soma[i][j]);
        }
        printf("\n");
    }
    
   

    return 0;
}
