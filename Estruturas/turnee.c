#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct celula{
    char *cidade;
    struct celula *prox;
    
}celula;


celula *iniciafila(){
    celula *p;
    p = malloc(sizeof(celula));
    p->prox = NULL;
    return p;
}


void insere(celula *p){
    
    celula *novo;
    
    
    novo = malloc(sizeof(celula));
    p->prox = novo;
    novo->prox = NULL;
    
    novo->cidade = malloc(sizeof(char)*27);    
}


celula *mostraroqtem(celula *ptr){
    
    char cities[27];
    
    if(scanf(" %s", cities) != EOF){
        insere(ptr);
        strcpy(ptr->prox->cidade, cities);
        mostraroqtem(ptr->prox);        
    }
    else{
        return ptr;
    }
}


celula *ultimapos(celula *p, celula *u){

    if(p->prox->prox == NULL){
        
        return u;
    }
    else{
        
        u->prox = p->prox;
        p->prox = p->prox->prox;
        u->prox->prox = NULL; 
        return u->prox;
        
    }

}

void logicaDaTroca(celula *shows, celula *ultimo){

    printf("%s\n", shows->cidade);
    
    if(shows->prox == NULL){ return; }
    if((int)shows->prox->cidade[0] + 32 == (int)shows->cidade[strlen(shows->cidade) - 1]){ 
        ultimo = ultimapos(shows, ultimo);
    }
    
    logicaDaTroca(shows->prox, ultimo);
    
}

int main(){
    
    int y;
    
    srand(time(NULL));
    
    for (int i = 0; i < 45; i++) {
        int numeroAleatorio = rand();
        y++;
    }
    
    celula *shows, *ultimo;
    shows = iniciafila();
    ultimo = mostraroqtem(shows);
    logicaDaTroca(shows->prox, ultimo);

    return 0;
}