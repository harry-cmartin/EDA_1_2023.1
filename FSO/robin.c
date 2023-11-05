#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSOS 100

struct Processo {
    int pid;
    int tempo_execucao;
    int tempo_restante;
    int tempo_termino;
};

struct Processo processos[MAX_PROCESSOS];
int tempo_global = 0;
int janela_tempo;

void roundRobin(int n) {
    int i, processos_restantes = n;

    while (processos_restantes > 0) {
        for (i = 0; i < n; i++) {
            if (processos[i].tempo_restante > 0) {
                if (processos[i].tempo_restante > janela_tempo) {
                    tempo_global += janela_tempo;
                    processos[i].tempo_restante -= janela_tempo;
                } else {
                    tempo_global += processos[i].tempo_restante;
                    processos[i].tempo_termino = tempo_global;
                    processos[i].tempo_restante = 0;
                    processos_restantes--;
                }
            }
        }
    }
}

int compare(const void *a, const void *b) {
    const struct Processo *processoA = (const struct Processo *)a;
    const struct Processo *processoB = (const struct Processo *)b;
    return processoA->tempo_termino - processoB->tempo_termino;
}

int main() {
    int n, i;

    scanf("%d", &n);

    scanf("%d", &janela_tempo);

    for (i = 0; i < n; i++) {
        
        scanf("%d %d", &processos[i].pid, &processos[i].tempo_execucao);
        processos[i].tempo_restante = processos[i].tempo_execucao * 1000; // Convertendo segundos para milissegundos
    }

    roundRobin(n);

    qsort(processos, n, sizeof(struct Processo), compare);

   
    for (i = 0; i < n; i++) {
        printf("%d (%d)\n", processos[i].pid, processos[i].tempo_termino);
    }

    return 0;
}
