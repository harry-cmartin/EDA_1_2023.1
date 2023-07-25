#include<stdio.h>
#include<string.h>

void main(){
    char letra;
    char palavra[1001];
    int numeroDePalavras = 0, numeroDeAparicoes = 0;

    scanf("%c\n",&letra);

    fgets(palavra,1001,stdin);

    char *separa = strtok(palavra, " ");

    while(separa != NULL) {
        numeroDePalavras++;

        if (strchr(separa,letra) != NULL) {
            numeroDeAparicoes++;
        }
        separa = strtok(NULL, " ");
    }

    if(numeroDePalavras>0){
        float resultado = (float)numeroDeAparicoes/numeroDePalavras*100;
        printf("%.1f",resultado);
    }else{
        printf("0.0\n");
    }
    return 0;
}



