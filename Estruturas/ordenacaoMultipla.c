#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double nota;
    int membro;
    int posicao;
} Problema;


void trocar(Problema* a, Problema* b) {
    Problema temp = *a;
    *a = *b;
    *b = temp;
}


Problema selecionarPivo(Problema arr[], int baixo, int alto) {
    int meio = baixo + (alto - baixo) / 2;
    if (arr[meio].nota < arr[baixo].nota) {
        trocar(&arr[meio], &arr[baixo]);
    }
    if (arr[alto].nota < arr[baixo].nota) {
        trocar(&arr[alto], &arr[baixo]);
    }
    if (arr[meio].nota < arr[alto].nota) {
        trocar(&arr[meio], &arr[alto]);
    }
    return arr[alto];
}


int particionar(Problema arr[], int baixo, int alto) {
    Problema pivo = selecionarPivo(arr, baixo, alto);
    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j].nota > pivo.nota || (arr[j].nota == pivo.nota && arr[j].membro < pivo.membro) || (arr[j].nota == pivo.nota && arr[j].membro == pivo.membro && arr[j].posicao < pivo.posicao)) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void quickSort(Problema arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    while (casos_teste--) {
        int n, m;
        scanf("%d %d", &n, &m);


        Problema* problemas = (Problema*)malloc(n * m * sizeof(Problema));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lf", &problemas[i * m + j].nota);
                problemas[i * m + j].membro = i + 1;
                problemas[i * m + j].posicao = j + 1;
            }
        }

       
        quickSort(problemas, 0, n * m - 1);

        
        for (int i = 0; i < n * m; i++) {
            printf("%d,%d ", problemas[i].membro, problemas[i].posicao);
        }
        printf("\n");

       
        free(problemas);
    }

    return 0;
}
