#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[1001];
    int num;
    int n,x,y,aux;

    while (scanf(" %i", &num) != EOF){
        vetor[n] = num;
        n++;
    }
    //analisa valor da esquerda
    for(x=0;x<n;x++){
        //analisa valor da direita
        for(y=x+1;y<n;y++){
            //troca valor
            if(vetor[x]>vetor[y]){
                aux=vetor[x];
                vetor[x]=vetor[y];
                vetor[y]=aux;
            }
        }
    }


    for (int i = 0; i < n; i++){
        printf("%i ", vetor[i]);
    }
}

