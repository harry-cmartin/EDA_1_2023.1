
#include <stdio.h>
#include <string.h>

int uppercase(char x){
    
    if(x >= 'A' && x <= 'Z'){
        
        return 1;
    }else{
        
        return 0;
    }
    
}

int lowercase(char x){
    
    if(x >= 'a' && x <= 'z'){
        
        return 1;
        
    }else{
        
        return 0;
    }
    
}

int isnumber(char x){
    
    if(x >= '0' && x <= '9'){
        
        return 1;
        
    }else{
        
        return 0;
    }
    
    
    
}

int main()
{
    int n,m,a,k;
    int upper =0 ,lower = 0 ,number = 0;
    char palavra[1001];
    
    scanf("%d %d %d %d", &n, &m,&a, &k);
    
    scanf("%s", palavra);
    
    int len = strlen(palavra);
    
    
    
    for(int i = 0; i < len; i++){
        
        if(uppercase(palavra[i])){
            upper++;
            
        }else if(lowercase(palavra[i])){
            
            lower++;
            
        }else if(isnumber(palavra[i])){
            
            number++;
        }
        
    }
    
    
    if(len < n){
        printf("Ufa :)\n");
        
    }else if(upper < a){
        
        printf("Ufa :)\n");
    }else if(lower <m){
        
        printf("Ufa :)\n");
    }else if(number < k){
        
        printf("Ufa :)\n");
    }else{
        
        printf("Ok =/");
    }
    return 0;
}
