

#include <stdio.h>
#include <stdlib.h>

int f91(int n);

int main()
{
    int p;
    
   while(scanf("%d", &p) == 1){
       
       if(p != 0){
           
           printf("f91(%d) = %d\n",p,f91(p));
       }else{
           
           exit(0);
       }
       
       
   }

    return 0;
}


int f91(int n){
    
    if(n >= 101){
        n = n - 10;
        return n;
    }else{
        
        n = f91(f91(n + 11));
        
        return n;
        
        
    }
    
    
}