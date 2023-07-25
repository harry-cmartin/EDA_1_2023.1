

#include <stdio.h>
#include <stdlib.h>



void merge(int *v, int r, int l, int meio){
    
    int R[l - r + 1];
    int left = r, j = meio + 1, k = 0, cont;
    int new = 0;
    
    while (left <= meio && j <= l)
    {
        if (v[left] <= v[j])
        {
            R[k++] = v[left++];
        }
        else
        {
            R[k++] = v[j++];
        }
    }

    while (left <= meio)
    {
        R[k++] = v[left++];
    }
    while (j <= l)
    {
        R[k++] = v[j++];
    }

   
    for (cont = r; cont <= l; ++cont)
    {
        v[cont] = R[new++];
    }
}


void mergeSort(int *v, int r, int l){
    
    if (r >= l)
        return;

    int meio = r + (l - r) / 2;
    mergeSort(v, r, meio);
    mergeSort(v, meio + 1, l);
    merge(v, r, l, meio);
}


int procurar(int *v, int l ,int r, int procurado){
    
    while (l + 1 < r){
        
        int meio = (r + l) / 2;
        
        if (procurado >= v[meio])
            l = meio;
        if (procurado < v[meio])
            r = meio;
    }
    
    
    return v[l] == procurado ? l : -1;
}
   




int main(){
    
    int *r, entrada1;
    int entrada2, i;
    
    scanf("%d", &entrada1);
    
    r = malloc(entrada1 * sizeof(int));

    for (i = 0; i < entrada1; i++)
        scanf("%d", &r[i]);

    mergeSort(r, 0, entrada1 - 1);

    while (scanf("%d", &entrada2) != EOF)
    
        procurar(r, 0, entrada1 - 1, entrada2) == -1 ? printf("nao\n") : printf("sim\n");

    return 0;
    
    return 0;
}
