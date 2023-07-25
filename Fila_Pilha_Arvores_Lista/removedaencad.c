
#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) { // verifica se o próximo nó existe
        return 0;
    }
    celula *q = p->prox; // armazena o próximo nó em q
    p->prox = q->prox; // remove o próximo nó da lista
    free(q); // libera a memória alocada
    return 1;
}

void remove_elemento(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL && p->prox->dado != x) { // encontra o nó com o valor x
        p = p->prox;
    }
    if (p->prox == NULL) { // verifica se não encontrou o valor x
        return;
    }
    celula *q = p->prox; // armazena o nó a ser removido em q
    p->prox = q->prox; // remove o nó da lista
    free(q); // libera a memória alocada
}

void remove_todos_elementos(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL) {
        if (p->prox->dado == x) { // verifica se o próximo nó tem o valor x
            celula *q = p->prox; // armazena o nó a ser removido em q
            p->prox = q->prox; // remove o nó da lista
            free(q); // libera a memória alocada
        } else {
            p = p->prox; // avança para o próximo nó
        }
    }
}

/*
void imprime(celula *le){
    
    celula *a = le->prox;
    
    while(a!=NULL) {

        printf("%d -> ", a->dado);
        a = a->prox;
        
    }
    
    if(a == NULL){
        
        printf("NULL\n");
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

p1->dado = 6;
p2->dado =90;
p3->dado = 7;
p4->dado = 2;
p5->dado = 7;
p6->dado = 18;

p1->prox = p2;
p2->prox = p3;
p3->prox = p4;
p4->prox = p5;
p5->prox = p6;
p6->prox = NULL;
l->prox = p1;




imprime(l);
remove_depois(l);
imprime(l);
remove_elemento(l,2);
imprime(l);
remove_todos_elementos(l,7);
imprime(l);

/*
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


