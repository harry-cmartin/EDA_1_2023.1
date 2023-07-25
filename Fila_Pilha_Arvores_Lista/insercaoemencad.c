
#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    
    int dado;
    struct celula *prox;
    
} celula;

void insere_inicio(celula *le, int x){  
    
    celula *a = malloc(sizeof(celula));
    
    a->dado = x;
    a->prox = le->prox;
    le->prox = a;
    
}

celula *busca_node_ant_item(celula *le, int x)
{
    celula *atual = le->prox;
    celula *anterior = NULL;
    
    while(atual != NULL && atual->dado!=x){
        anterior = atual;
        atual= atual->prox;
    }
    
    if(atual==NULL) anterior == NULL;
    
    return anterior;
}

void insere_antes (celula *le, int x, int y){
    
    celula *nova = malloc(sizeof(celula));
    
    celula *achado = busca_node_ant_item(le,y);
    
    nova->dado = x;
    nova->prox = achado->prox;
    achado->prox = nova;

}

/*
void imprime(celula *le){
    
    celula *a = le->prox;
    
    while(a!=NULL) {
        
       
        
        printf("%d -> ", a->dado);
        a = a->prox;
        
    }
    
    if(a == NULL){
        
        printf("NULL");
    } 
    
}

int main()
{
    
    
    celula *l1 = malloc(sizeof(celula));
l1->prox = NULL;

celula *l2 = malloc(sizeof(celula));
l2->prox = NULL;

celula *l = malloc(sizeof(celula));
l->prox = NULL;

celula *p1 = malloc(sizeof(celula));
celula *p2 = malloc(sizeof(celula));
celula *p3 = malloc(sizeof(celula));
celula *p4 = malloc(sizeof(celula));
celula *p5 = malloc(sizeof(celula));
celula *p6 = malloc(sizeof(celula));

p1->dado = 10;
p2->dado = 4;
p3->dado = -9;
p4->dado = 2;
p5->dado = 7;
p6->dado = 10;

p1->prox = p2;
p2->prox = p3;
p3->prox = p4;
p4->prox = p5;
p5->prox = p6;
p6->prox = NULL;
l->prox = p1;

insere_inicio(l,100);
insere_inicio(l,4009);
insere_antes(l,45,100);
insere_antes(l,80,7);
imprime(l);

free(p1);
free(p2);
free(p3);
free(p4);
free(p5);
free(p6);
free(l);


    return 0;
}
*/