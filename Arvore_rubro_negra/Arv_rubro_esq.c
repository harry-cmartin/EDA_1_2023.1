#include <stdio.h>

enum cor {vermelho, preto};

typedef struct no
{
    int dado;
    struct no *esq, *dir;
    enum cor cor;   
}no;

no *rotacao_esquerda(no *raiz){

    no* x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = vermelho;

    return x;
}

no *rotacao_direita(no *raiz){

    no* a = raiz->dir;
    raiz->esq = a->dir;
    a->dir = raiz;
    a->cor = raiz->cor;
    raiz->cor = vermelho;

    return a;
}

void sobe_cor(no *raiz){

    raiz->cor = vermelho;
    raiz->esq->cor = preto;
    raiz->dir->cor = preto;
}

void insere(no *raiz, int ch){

    raiz = insere_rec(raiz, ch);
    raiz->cor = preto;
    return raiz;
}

no *insere_rec(no *raiz, int ch){

    if (raiz == NULL){

        no *novo = malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        novo->dado = ch;
        novo->cor = vermelho;
        return novo;

    }
    if (ch < raiz->dado){
        
        raiz->esq = insere_rec(raiz->esq, ch);
    }
    else raiz->dir = insere_rec(raiz->dir, ch);
}

no *corrige(no *raiz){

    if (raiz->esq->cor == preto && raiz->dir->cor == vermelho){
        return rotacao_esquerda(raiz);
    }

    if (raiz->esq->cor == vermelho && raiz->dir->cor == vermelho){
        sobe_cor(raiz);
        return raiz;
    }
    
    if(raiz->esq->cor == vermelho && raiz->esq->esq->cor == vermelho){
        raiz = rotacao_direita(raiz);
        sobe_cor(raiz);
        return raiz;
    }
}