
#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *p = le->prox;
    while(p != NULL && p->dado != x){
        p = p->prox;
    }
    return p;
}

celula *busca_rec (celula *le, int x){
    if (le == NULL || le->dado == x){
        return le;
    } else{
        return busca_rec(le->prox, x);
    }
}

/*int main() {

celula *le = malloc(sizeof(celula));
le->prox = NULL;

celula *p1 = malloc(sizeof(celula));
celula *p2 = malloc(sizeof(celula));
celula *p3 = malloc(sizeof(celula));

p1->dado = 1;
p2->dado = 2;
p3->dado = 3;

p1->prox = p2;
p2->prox = p3;
p3->prox = NULL;
le->prox = p1;

int x = 5;

celula *resultado = busca_rec(le, x);

if (resultado != NULL){
    printf("o valor %d foi encontrado na lista", x);
} else {
    printf("o valor %d não foi encontrado na lista", x);
}

free(p1);
free(p2);
free(p3);
free(le);

    return 0;
}*/