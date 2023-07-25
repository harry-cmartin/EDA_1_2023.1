
#include <stdio.h>

int main(){
    
    int xm, ym , xr,yr;

    scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
 
    int resultado = abs(xr - xm) + abs(yr - ym);

    printf("%d\n", abs(resultado));

    return 0;
}
