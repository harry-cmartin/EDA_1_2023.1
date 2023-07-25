#include <stdio.h>
#include <string.h>

int main(){
    int vetor[1000];
    int menorvalor;
    int aux;
    int n=0;
    int num=0;

    while (scanf(" %i", &num) != EOF){
        vetor[n] = num;
        n++;
    }

    for(int i=0;i<n;i++){
        menorvalor=i;

        for(int j=i+1;j<n;j++){
            if(vetor[j]<vetor[menorvalor]){
                menorvalor=j;
            }
        }
        if(menorvalor != i){
           aux=vetor[i];
           vetor[i]=vetor[menorvalor];
           vetor[menorvalor]=aux;
        }
    }

    for(int x=0;x<n;x++){
        printf("%d ",vetor[x]);
    }

}
