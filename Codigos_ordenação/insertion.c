#include <stdio.h>

int main(){

    int vetor[50000];
    int j,atual;
    int x;
    int z=0;

    while(scanf("%d",&x)!=EOF){
        vetor[z]=x;
        z++;
    }

    for(int i=1;i<z;i++){
        //Elemento atual em análise
        atual=vetor[i];

        //Elemento anterior ao analisado
        j = i - 1;

        //Analisando membros anteriores
        while((j>=0)&&(atual<vetor[j])){
            //Posiciona os elmeentos uma posição para frente
            vetor[j+1]=vetor[j];

            //Faz o j andar para trás
            j=j-1;
        }
        //menor numero
        vetor[j+1] = atual;
    }

    for(int n = 0; n < z; n++){
        printf("%d ",vetor[n]);
    }
}
