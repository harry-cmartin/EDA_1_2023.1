
#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        
        return 0;
    }

    *y = f->dados[f->p];
    f->p++;

    return 1;
}

/*
void imprimeFila(fila *f) {
    int i;

    for (i = f->p; i < f->u; i++) {
        printf("fila %d ", f->dados[i]);
    }

    printf("\n");
}

int main() {
   
    fila f;
    f.N = 5; 
    f.dados = (int*)malloc(f.N * sizeof(int));
    f.p = 0; 
    f.u = 0; 

    int i;
    for (i = 0; i < 4; i++) {
        f.dados[f.u] = i + rand();
        f.u++;
    }
    
    imprimeFila(&f);
   
    int elemento;
    while (desenfileira(&f, &elemento)) {
        printf("lemento desenfileirado: %d\n", elemento);
    }
    free(f.dados);

    return 0;
}
*/