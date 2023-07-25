

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int T,N;
    int pontos, Vitorias;
    
    while(scanf("%d %d", &T, &N) == 2){
        
        if(T == 0){
            exit(0);
        }
        
        Vitorias = N * 3;
        
        for(int i = 0; i < T; i++){
            
            scanf("%*s %d", &pontos);
            
            Vitorias -= pontos;
            
        }
        printf("%d\n", Vitorias);
        
        Vitorias = 0;
        pontos = 0;
        T = 0;
        N = 0;
    }
   
    
    return 0;
}

