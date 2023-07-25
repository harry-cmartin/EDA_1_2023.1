
#include <stdio.h>

int main(){
    
    float a,g,ra,rg;
    
    scanf("%f %f %f %f", &a, &g, &ra, &rg);
    
    float resa, resg;
    resa = ra/a;
    resg = rg/g;
    
    if(resa > resg){
        printf("A\n");
 
    }else{
        printf("G\n");
    
    }
    
    
    return 0;
}
