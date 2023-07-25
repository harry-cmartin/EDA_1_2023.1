
#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    
    int dado;
    struct celula *prox;
    
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
    
    celula *p = l->prox;
    
    while(p != NULL){
        
        if (p->dado % 2 == 0){
            
            l2->prox = p;
            l2 = l2->prox;
            
        } else {
            
            l1->prox = p;
            l1 = l1->prox;
        }
        
        p = p->prox;
    }
    
    l1->prox = NULL;
    l2->prox = NULL;
    
}

/*
void imprimir_lista(celula *le){
    celula *p = le->prox;
    while(p != NULL){
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("\n");
}

int main() {
    
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

divide_lista(l, l1, l2);
imprimir_lista(l1);
imprimir_lista(l2);

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