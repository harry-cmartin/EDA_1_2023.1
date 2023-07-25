
#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
int dado;
struct celula *prox;
} celula;


int desenfileira (celula *f, int *y){
    
    if(f->prox == NULL){
        return 0;
    }
    
    celula *temp = f->prox;
    *y = temp->dado;
    f->prox = temp->prox;
    free(temp);
    
    return 1;
}

/*
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