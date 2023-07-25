

#include <stdio.h>

int vetor[1000000];

void merge(int *v, int r, int l, int meio){
    
    int R[l - r + 1];
    int left = r, j = meio + 1, k = 0, cont;
    int new = 0;
    
    while (left <= meio && j <= l)
    {
        if (vetor[left] <= vetor[j])
        {
            R[k++] = vetor[left++];
        }
        else
        {
            R[k++] = vetor[j++];
        }
    }

    while (left <= meio)
    {
        R[k++] = vetor[left++];
    }
    while (j <= l)
    {
        R[k++] = vetor[j++];
    }

   
    for (cont = r; cont <= l; ++cont)
    {
        vetor[cont] = R[new++];
    }
}

int main(){
    
    int entrada, i, j;
    int posicao = 0;
    
    for (i = 0; i < 8; ++i){
        
        scanf("%d", &entrada);
        
        if (entrada == 0)
            continue;
            
        for (j = 0; j < entrada; ++j)
        
            scanf("%d", &vetor[posicao + j]);
            
        merge(&vetor[0], 0, posicao + entrada - 1, posicao - 1);
        
        
        posicao += entrada;
    }

    printf("%d", vetor[0]);
    
    for (i = 1; i < posicao; ++i){
        
        printf(" %d", vetor[i]);
        
        
    }    
    return 0;
}