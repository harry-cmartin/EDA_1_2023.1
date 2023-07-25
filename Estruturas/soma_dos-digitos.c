

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Somaosdigitos(char *Numero, int i, int soma){
    
    soma+=(Numero[i]-48);
    
    i++;
    
    if(Numero[i]=='\0'){
        
        return soma;
    }
    
    return Somaosdigitos(Numero, i, soma);
}



int main(){
    
    char Numero[14];
    
    int i = 0; 
    int soma = 0;
    
    scanf("%s", Numero);
    
    
    printf("%d\n", Somaosdigitos(Numero, i, soma));
    
    return 0;
}