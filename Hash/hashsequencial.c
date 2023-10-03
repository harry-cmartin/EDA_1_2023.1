#include <stdio.h>
#include <stdlib.h>

//15 -> numero de chaves 
//logo: 2 *15 = 30 -> primo mais prox = 31


#define TAM 31

void inicializarTabela(int t[]){
    
    int i;
    
    for(i = 0;i <TAM;i++){
        t[i] = -1; //Nesse caso 0 NÃO faz parte do conjunto de possiveis chave
    }
}

int hash(int chave){
    
    return chave % TAM;
    
}

void inserir(int chave,int table[]){
    
    int id = hash(chave);
    
    while(table[id] != -1){
        id = hash(id + 1);
        
    }
    
    table[id] = chave;
}

int busca(int table[], int chave){
    
    int id = hash(chave);
    
    while(table[id] != -1){
        if(table[id] == chave){
            printf("INDICE: %d\n",id);
            return table[id];
        }else{
            id = hash(id + 1);
        }
    }
    
    return 0;
    
}

void imprime(int table[]){
    
    int i;
    
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i,table[i]);
        
    }
}

int main()
{
    int opcao,tabela[TAM];
    int chave,retorno;
    inicializarTabela(tabela);
    
   
    do{
        
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
        
            imprime(tabela);
            break;
        case 2:
            scanf("%d", &chave);
            retorno = busca(tabela, chave);
            if(retorno == 0){
                printf("n existe essa chave\n");
            }else{
                printf("VALOR: %d\n", retorno);
                
            }
            break;
        case 3:
        printf("Insira um num\n");
            scanf("%d", &chave);
            inserir(chave, tabela);
            break;
        default:
            printf("N EXISTE");
            break;
        }
        
    }while(opcao != 0);
    
    return 0;
}