
#include<stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;



int enfileira (fila *f, int x){
    
    if(f->u == f->N){
        f->dados = (int*)realloc(f->dados, 2 * f->N * sizeof(int));
        
        if(f->dados == NULL){
            return 0;
            
        }
        f->N =2 *f->N;
    }
    f->dados[f->u] = x;
    f->u = f->u + 1;
    
    return 1;
}

/*
void print_fila(fila *f) {
    int i = f->p;
    
    do{
        printf("%d ", f->dados[i]);
        i = (i + 1) % f->N;
    
    }while (i != f->u);
    
    printf("\n");
}

int main(){
    fila f;
    f.N = 6;

    f.dados = (int*)malloc(f.N * sizeof(int));
    f.p = f.u = 0;

    enfileira(&f,1);
    enfileira(&f,2);
    enfileira(&f,3);
    enfileira(&f,4);
    enfileira(&f,5);

    print_fila(&f);
}

*/