
#include <stdio.h>


typedef struct{
    
    int *v;
    int n,tam;
    
}FP;


FP *cria_heap(int tam){
    
    FP *g = malloc(sizeof(FP));
    g->v = malloc(tam * sizeof(int))
    g->n = 0;
    g->tam = tam;
    
    return g;
    
}

void troca(int *V, int i, int j){
    
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    
    
}

int pai(int i){
    
    return (i-1)/2
    
}

void desce(FP *fp, int i){
    
    int maior_fi,esq = 2*1 + 1, dir = esq + 1;
    
    if(esq < fp->n){
        maior_fi = esq;
        
        if(dir < fp->n && fp->v[dir] > fp->v[maior_fi] ){
            maior_fi = dir;
            
        }
        
        if(fp->v[i] < fp->v[maior_fi]){
            troca(fp->v,i, maior_fi);
            desce(fp, maior_fi);
        }
    }
    
    
}

int remover(FP *fp){
    
    troca(fp->v,0,fp->n - 1);
    fp->n--;
    desce(fp,0);
    
   return fp->v[fp->n]; 
    
}

void sobe(FP *fp, int i){
    
    if(i > 0 && fp->v[i] > fp->v[pai(i)]){
        
        troca(fp->v,pai(i),i);
        sobe(fp,pai(i));
    }
    
}


void insere_heap(FP *g, int ch){
    
    g->v[n] = ch;
    g->n++;
    sobe(fp->v,fp->n - 1);
    
}

int main()
{
    printf("Hello World");

    return 0;
}
