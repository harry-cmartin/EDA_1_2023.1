#include <stdio.h>
#include <stdlib.h>

//15 -> numero de chaves 
//logo: 2 *15 = 30 -> primo mais prox = 31


#define TAM 31

typedef struct no{
    
    int chave;
    struct no *prox;
    
}no;

typedef struct lista{
    
    no *inicio;
    int tamanho;
    
}lista;

void inicializalista(lista *l){
    l->inicio = NULL;
    l->tamanho = 0;
}


int remove_(lista *l, int valor){
    
    
    no *aux = l->inicio;
    
    if(aux == NULL){
      printf("NÃO EXISTE ESSA CHAVE\n");
        return 0;
    }
    
    if(aux->chave == valor){
        
        l->inicio = aux->prox;
        l->tamanho--;
        printf("REMOVIDO COM SUCESSO\n");
        return 1;
    }else{
    
        while(aux->prox != NULL && aux->prox->chave != valor ){
            aux = aux->prox;
        }
        
        
        if(aux->prox == NULL){
            printf("NÃO EXISTE ESSA CHAVE\n");
            return 0;
        }
        
       
        no *new = aux->prox;
        aux->prox = new->prox;
        l->tamanho--;
        printf("REMOVIDO COM SUCESSOooo\n");
        return 1;
    }
    return 0;
}

int buscar_na_lista(lista *l, int valor){
    
    no *aux = l->inicio;
    
    while(aux && aux->chave != valor){
        aux = aux->prox;
        if(aux){
            return aux->chave;
            
        }else{
            return 0;
        }
    }
    
}


void inserir_na_lista(lista *l, int valor){
    no *novo = malloc(sizeof(no));
    
    if(novo){
        
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tamanho++;
    }else{
        printf("ERRO");
    }
    
    
}

void imprimir_lista(lista *l){
    
    no *aux = l->inicio;
    printf("Tam : %d ", l->tamanho);
    
    while(aux){
        printf("%d ", aux->chave);
        aux = aux ->prox;
    }
    
    
}

void inicializarTabela(lista t[]){
    int i;
    
    for(i = 0;i <TAM;i++){
        inicializalista(&t[i]);
    }
}

int hash(int chave){
    
    return chave % TAM;
    
}

void inserir(int chave,lista table[]){
    
    int id = hash(chave);
    inserir_na_lista(&table[id],chave);
 
}

int busca(lista table[], int chave){
    
    int id = hash(chave);
    printf("INDICE %d\n", id);
    return buscar_na_lista(&table[id],chave);
    
}

void remover(lista table[], int valor){
    
    int id = hash(valor);
    remove_(&table[id], valor);

    
}


void imprime(lista table[]){
    
    int i;
    
    for(i = 0; i < TAM; i++){
        printf("%d = ", i);
        imprimir_lista(&table[i]);
        printf("\n");
    }
}

int main()
{
    int opcao;
    lista tabela[TAM];
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
            
        case 4: 
            printf("digite um neum para remover\n");
            scanf("%d\n", &chave);
            remover(tabela,chave);
            break;
        default:
            printf("N EXISTE\n");
            break;
        }
        
    }while(opcao != 0);
    
    return 0;
}