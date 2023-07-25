

#include <stdio.h>

int main(){
    
    int contador, codigo, nota, restaurantes;
    
    int maiorNota;
    
    int codigovencedor;

    contador = 1;
    
    while(scanf ("%d", &restaurantes) == 1){
        
        scanf("%d %d", &codigovencedor, &maiorNota);
        
        for(int i = 1; i < restaurantes; i++){
            
            scanf("%d %d", &codigo, &nota);
            
            if(nota > maiorNota || (nota == maiorNota && codigo < codigovencedor)){
                
                maiorNota = nota;
                codigovencedor = codigo;
            }
        }
        
        
        
        
        printf("Dia %d\n%d\n", contador, codigovencedor);
        contador++;
    }
    return 0;
}