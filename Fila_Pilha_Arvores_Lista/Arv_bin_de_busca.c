
#include <stdio.h>

typedef struct{
    
    int dado;
    struct no *esq, *dir;
    
}no;

void largura (no *raiz){
    
    enfileira(raiz);
    
    while(!FILA_vazia){
        
        no *r = desenfileira();
        printf("%d", r->dado);
        if(raiz->esq != NULL) enfileira(raiz->esq);
        if(raiz->dir != NULL)enfileira(raiz->dir);
        
    }
    
}

no *busca_Rec(no *raiz, int ch){
    
    if(raiz){
        
        if(ch == raiz->dado ){
            return raiz;
        }else if(ch <raiz->dado){
            
            return busca_Rec(raiz->esq, ch);
            
        }else{
            
            return busca_Rec(raiz->dir,ch);
            
        }
        
        return raiz;
    }
    
    
    
}

no *busca_int(no *raiz,int ch){
    
    while(raiz != NULL && raiz->dado != ch){
        
        if(ch < raiz->dado){
            
            raiz = raiz->esq;
            
        }else{
            
            raiz = raiz->dir;
            
        }
        
    }
    
    return raiz;
}

no *insere_rec(no *raiz,int ch){
    
    if(!raiz){
        
        no *novo = malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        novo->dado = ch;
    
        return novo;
    }
    
    if(ch < raiz->dado){
        
        raiz->esq = insere_rec(raiz->esq,ch);
        
    }else if( ch > raiz->dado){
        
        raiz->dir = insere_rec(raiz->dir,ch);
    }else{
        printf("NAO SAO PERMITIDAS CHAVES IGUAIS");
        
    }
    
    return raiz;
    
}


no *remover(no *raiz, int ch){
    
    if(raiz){
        
        if(raiz->dado == ch){ 
            
            if(raiz->esq == NULL && raiz->dir == NULL){
               
                free(raiz);
                return NULL;
                
            }else if(raiz->esq == NULL || raiz->dir == NULL){
                    no *aux2
                if(raiz->esq != NULL){
                    aux2 = raiz->esq;
                }else{
                    aux2 = raiz->dir
                }
                free(raiz);
                return aux2;
                
                
            }else{
                no *aux = raiz->esq;
                while(aux->dir != NULL){
                    aux = aux->dir;
                }
                raiz->dado =aux->dado;
                aux->dado = ch;
                raiz->esq = remover(raiz->esq,ch);
                
                return raiz;
            }
        
        }
    }else{
        
        if(ch < raiz->dado){
            
            raiz->esq = remover(raiz->esq,ch);
            
        }else{
            
            raiz->dir = remover(raiz->dir,ch);
        }
        
        return raiz;
        
    }
    
    
    
}



int main()
{
    printf("Hello World");

    return 0;
}
