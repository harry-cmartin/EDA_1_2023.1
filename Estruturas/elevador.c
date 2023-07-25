
#include <stdio.h>

int main() {
    int n, c, s, e;
    int pessoas = 0, exc= 0;
    
    scanf("%d %d", &n, &c);
    
    for (int i = 0; i < n; i++) {
        
        scanf("%d %d", &s, &e);
        
        pessoas -= s; 
        pessoas += e; 
        
        if (pessoas > c) { 
            exc = 1;
            break;
        }
        
    }
    
    if (exc == 1) { 
        
        printf("S\n");
        
    } else { 
        printf("N\n");
    }
    return 0;
}