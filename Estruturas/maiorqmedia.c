#include <stdio.h>
#include <stdint.h> 
#include <inttypes.h>
#include <stdlib.h>

int main() {
    int32_t N; 
    scanf("%" SCNd32, &N); 

    int64_t soma = 0;
    int32_t *vetor = malloc(N * sizeof(int32_t)); 
    for (int i = 0; i < N; i++) {
        scanf("%" SCNd32, &vetor[i]);
        soma += vetor[i]; 
    }

    double media = (double)soma / N; 

    int tem_maior = 0; 
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (tem_maior) {
                printf(" ");
            }
            printf("%" PRId32, vetor[i]); 
            tem_maior = 1;
        }
    }

    if (!tem_maior) {
        printf("0");
    }

    free(vetor); 

    return 0;
}

