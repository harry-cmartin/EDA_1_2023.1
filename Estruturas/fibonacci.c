

#include <stdio.h>

long int memorizedFib[81] = {[0 ... 80] = -1};

long int fibonacci(int n){
    
   
   
   memorizedFib[1] = 1;
   memorizedFib[2] = 1;
    

   
    if(memorizedFib[n] != -1){
        
        return memorizedFib[n];
        
    }else{
        
        memorizedFib[n] = fibonacci(n - 1) + fibonacci(n - 2);
        
        return memorizedFib[n];
        
    }
   
   
    
}

