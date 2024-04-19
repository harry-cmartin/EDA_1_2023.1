#include <stdio.h>

int main() {
    int limite_x, limite_y, num_passos, mov_PA, mov_PB;
    int pos_x_PA = 1, pos_y_PA = 1, pos_x_PB, pos_y_PB;
    int encontrou = 0, passo_encontro = 0, x_encontro, y_encontro;

    scanf("%d %d", &limite_x, &limite_y);
    scanf("%d", &num_passos);

    pos_x_PB = limite_x;
    pos_y_PB = limite_y;

    for (int i = 1; i <= num_passos; i++) {
        scanf("%d %d", &mov_PA, &mov_PB);

        switch (mov_PA) {
            case 1: pos_y_PA++; break;
            case 2: pos_y_PA--; break;
            case 3: pos_x_PA++; break;
            case 4: pos_x_PA--; break;
        }

        switch (mov_PB) {
            case 1: pos_y_PB++; break;
            case 2: pos_y_PB--; break;
            case 3: pos_x_PB++; break;
            case 4: pos_x_PB--; break;
        }

        if ((pos_x_PA < 1 || pos_x_PA > limite_x || pos_y_PA < 1 || pos_y_PA > limite_y) &&
            !encontrou) {
            encontrou = 1;
            passo_encontro = i;
            x_encontro = pos_x_PA;
            y_encontro = pos_y_PA;
        } else if ((pos_x_PB < 1 || pos_x_PB > limite_x || pos_y_PB < 1 || pos_y_PB > limite_y) &&
                   !encontrou) {
            encontrou = 2;
            passo_encontro = i;
            x_encontro = pos_x_PB;
            y_encontro = pos_y_PB;
        } else if (pos_x_PA == pos_x_PB && pos_y_PA == pos_y_PB && !encontrou) {
            encontrou = 3;
            passo_encontro = i;
            x_encontro = pos_x_PA;
            y_encontro = pos_y_PA;
        }
    }

    switch (encontrou) {
        case 1: printf("PA saiu na posicao (%d,%d) no passo %d\n", x_encontro, y_encontro, passo_encontro); break;
        case 2: printf("PB saiu na posicao (%d,%d) no passo %d\n", x_encontro, y_encontro, passo_encontro); break;
        case 3: printf("Encontraram-se na posicao (%d,%d) no passo %d\n", x_encontro, y_encontro, passo_encontro); break;
        default: printf("Nao se encontraram\n"); break;
    }

    return 0;
}
