
#include <stdio.h>

int main(){
    
    int a,b,c;
    int x,y,z;
    
    scanf("%d %d %d", &a,&b,&c );
    scanf("%d %d %d", &x,&y,&z );
    
    int alt,larg,comp;
    
    alt = z/c;
    larg = y/b;
    comp = x/a;
    
    int res = alt * comp * larg;
    
    printf("%d", res);
    
    return 0;
}
