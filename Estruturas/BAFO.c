
#include <stdio.h>

int main() {
    int r, a, b, i, somaA, somaB, teste = 1;
    
    while(1) {
        scanf("%d", &r);
        if(r == 0) break;
        
        somaA = 0;
        somaB = 0;
        
        for(i = 0; i < r; i++) {
            scanf("%d %d", &a, &b);
            somaA += a;
            somaB += b;
        }
        
        if(somaA > somaB){
               
               printf("Teste %d\nAldo\n\n", teste);
           }else{
               printf("Teste %d\nBeto\n\n", teste);
           }
           
        
        teste++;
    }
    
    return 0;
}