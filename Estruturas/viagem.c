
#include <stdio.h>

int main(){
    
    int l,d;
    int k,p;
    
    scanf("%d %d", &l, &d);
    scanf("%d %d", &k, &p);
    
    int custo = 0;
    custo = k * l;
    
    int pedagios = l/d;
    int resultado_pedagios = pedagios * p;
    
    int resul_dinal = custo + resultado_pedagios;
    
    printf("%d\n", resul_dinal);
    
    
    
    

    return 0;
}
