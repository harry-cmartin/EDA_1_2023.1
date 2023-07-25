

#include <stdio.h>
#include <string.h>
#define TAM_MAX 1000

int main(void){
    
  int i = 0,N;
  int linha, colunas;
  
  
  scanf("%i", &N);
  
  char frase[N][TAM_MAX]; 
  

  for (int i = 0; i < N; i++){
      
    scanf(" %10000[^\n]", frase[i]);
    
    
  }


  scanf("%i %i", &linha, &colunas);


  char funcao;
  
  
  while (scanf(" %c", &funcao) > 0){
      
    if (funcao == 'j'){
        
      if (linha < N){
        
          
        linha++;
      }
    
      
    }else if (funcao == 'k'){
        
      if (linha > 1){
          
        linha--;
      }
      
    }
    
    
    
    int tamanhodastring = strlen(frase[linha - 1]);

    if (tamanhodastring < colunas){
      printf("%i %i %c\n", linha, tamanhodastring, frase[linha - 1][tamanhodastring - 1]);
      
      
    }else
      printf("%i %i %c\n", linha, colunas, frase[linha - 1][colunas - 1]);
      
      
    }
    
    
    
  return 0;
  
}