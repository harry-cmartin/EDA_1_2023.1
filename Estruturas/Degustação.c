

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int tamanho;
    char c;
    int position;
    
} bebe;

void merge(bebe *tomados, int l, int r, int meio)
{
    bebe R[r - l + 1];
    int Left = l, j = meio + 1, k = 0, conta;
    int new = 0;
    
    while (Left <= meio && j <= r){
        
        if (tomados[Left].tamanho >= tomados[j].tamanho){
            
            R[k++] = tomados[Left++];
        }
        else{
            
            R[k++] = tomados[j++];
        }
    }

    while (Left <= meio){
        
        R[k++] = tomados[Left++];
        
    }
    while (j <= r){
        
        R[k++] = tomados[j++];
    }

    
    for (conta = l; conta <= r; ++conta){
        
        tomados[conta] = R[new++];
    }
    
    
}

void mergeSort(bebe *tomados, int l, int r){
    
    
    if (l >= r)
        return;

    int meio = l + (r - l) / 2;
    mergeSort(tomados, l, meio);
    mergeSort(tomados, meio + 1, r);
    merge(tomados, l, r, meio);
}




int main(){
    
    
    bebe tomados[100000];
    char entrada[100001];
    
    int i = 0, t = 0;
    int j;
    
    scanf("%s", entrada);

    int z = strlen(entrada);
    
    for (i = 0; i < z; i++){

        tomados[t].c = entrada[i];
        tomados[t].position = i;

        while (entrada[i] == tomados[t].c) {
            
            tomados[t].tamanho++;
            i++;
        }
        
        i--;
        t++;
    }

    mergeSort(&tomados[0], 0, t);

    for (j = 0; j < t; j++){
        
        printf("%d %c %d\n", tomados[j].tamanho, tomados[j].c, tomados[j].position);
    }

    return 0;
}