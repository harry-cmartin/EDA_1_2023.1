

#include <stdio.h>

int main(){
    
    int n, j, z, i;
    int TESTES = 1;
    int Acumulado;
    
    scanf("%i", &n);
    
    while(n != 0){
        
        Acumulado = 0;
        printf( "Teste %i\n", TESTES);
        TESTES++;
        
        for(i = 0; i < n; i++){
            scanf("%i %i", &j, &z);
            
            Acumulado += j - z;
            
            printf("%i\n", Acumulado);
        }
        printf("\n");
        scanf("%i", &n);
    }
    return 0;
}
