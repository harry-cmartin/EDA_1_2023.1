
#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p = l1->prox, *q = l2->prox, *r = l3;
    
    while (p != NULL && q != NULL) {
        if (p->valor <= q->valor) {
            r->prox = p;
            r = p;
            p = p->prox;
        } else {
            r->prox = q;
            r = q;
            q = q->prox;
        }
    }
    
    if (p != NULL) {
        r->prox = p;
    } else {
        r->prox = q;
    }
    
    l1->prox = NULL;
    l2->prox = NULL;
}

/*
int main() {
    celula *l1 = (celula*) malloc(sizeof(celula));
    celula *l2 = (celula*) malloc(sizeof(celula));
    celula *l3 = (celula*) malloc(sizeof(celula));
    
    l1->prox = (celula*) malloc(sizeof(celula));
    l1->prox->valor = 1;
    l1->prox->prox = (celula*) malloc(sizeof(celula));
    l1->prox->prox->valor = 3;
    l1->prox->prox->prox = NULL;
    
    l2->prox = (celula*) malloc(sizeof(celula));
    l2->prox->valor = 2;
    l2->prox->prox = (celula*) malloc(sizeof(celula));
    l2->prox->prox->valor = 4;
    l2->prox->prox->prox = NULL;
    
    l3->prox = NULL;
    
    mescla_listas(l1, l2, l3);
    
    celula *p = l3->prox;
    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
    
    free(l1->prox);
    free(l1);
    free(l2->prox);
    free(l2);
    free(l3);
    
    return 0;
}
*/