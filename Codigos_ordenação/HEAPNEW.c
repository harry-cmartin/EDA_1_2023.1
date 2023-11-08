#include <stdio.h>

typedef struct{
    
    int *v;
    int n, tam;

}FP;

FP *cria_heap(int tam){

    FP *fp = malloc(sizeof(FP));
    fp->v = malloc(tam * sizeof(int));
    fp->tam = tam;
    fp->n= 0;

    return fp;
}

int pai(int i){

    return (i-1)/2

}

void swap(int *v, int i, int j){

    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;


}

void fixup(FP *fp, int i){

    if(i > 0&& fp->v[pai(i)] < fp->v[i]){
        swap(fp->v,pai(i,i));
        fixup(fp, pai(i));

    }


}

void insere(FP *fp, int x){

    fp->v[fp->n] = x;
    fp->n++;
    fixup(fp,fp->n - 1);

}

void fixDown( FP *fp, int i){

    int maior_filho, esq = 2 * i +1, dir = esq +1

    if(esq < fp->n){
        maior_filho = esq;

        if(dir < fp->n && fp->v[dir] > fp->v[esq])
            maior_filho = dir;

        if(fp -> v[i] < fp-> v[maior_filho]){
            swap(fp->vm i, maior_filho);
            fixDown(fp,maior_filho);
        }
    }   
}

int remove( FP *fp){

    swap(fp->v,0,f->n - 1);
    fp->n--;
    fixDown(fp,0);

    return fp->v[fp->n];

}

void heapsort(int *v, int n){
    FP *fp = cria_heap(n);
    for (int i = 0; i < n; i++)
    {
        insere(fp, v[i]);
    }
    for (int i = n-1; i > 0; i--)
    {
        v[i] = remove(fp);
    }
}

//A funçâo a seguir não segue os prototipos acima
void heapsortheapfy(int *v, int n){

    for (int i = n/2; i > 0; i--)
    {
        fixDown(v, n, i);
    }
    while (n > 0)
    {
        remove(v);
        fixDown(v, n, i);
        n--;
    }
}