#include <stdio.h>
#include <stdlib.h>

int soma = 0;
int max = 0;

void ultra(int *vetor){
    if(vetor[0] == 0){
        return 0;
    }
    if(max <(vetor[0] + soma)){
        soma = 0;
        ultra( 1 + vetor );
        printf("%d\n", *vetor);
    }else{
        soma = soma + *vetor;
        ultra(vetor + 1);
    }
}


int main(){
    int vetor[550] = {[0 ... 500]=0};

    int num = 0;
    int i = 0;

    scanf("%d", &num);

    while (num != 0){
        vetor[i] = num;
        scanf("%d", &num);
        i = i + 1;
    }

    scanf("%d", &max);

    ultra(vetor);
    return 0;
}
