
#include <stdio.h>

int main() {
    int m,testes=0;
    
    while (1) {
        
        testes++;
        scanf("%d", &m);
        
        if (m == 0) {
            break;
        }
        
        int inicio, x;
        char op;
        
        scanf("%d", &inicio);
        
        for (int i = 1; i < m; i++) {
            
            scanf(" %c %d", &op, &x);
            
            if (op == '+') {
                inicio += x;
            } else {
                inicio -= x;
            }
        }
        printf("Teste %d\n%d\n",testes, inicio);
    }
    return 0;
}