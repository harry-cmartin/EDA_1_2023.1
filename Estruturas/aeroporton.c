
#include <stdio.h>

#define MAX 101

int main() {
    int a, v, x, y, i, j, max;
    int voos[MAX] = {0};

    int teste = 1;

    while (scanf("%d %d", &a, &v) == 2 && a != 0 && v != 0) {
        
        for (i = 1; i <= a; i++) {
            voos[i] = 0;
        }

        
        for (i = 0; i < v; i++) {
            scanf("%d %d", &x, &y);
            voos[x]++;
            voos[y]++;
        }

        
        max = 0;
        for (i = 1; i <= a; i++) {
            if (voos[i] > max) {
                max = voos[i];
            }
        }

        
        printf("Teste %d\n", teste++);
        for (i = 1, j = 0; i <= a; i++) {
            if (voos[i] == max) {
                if (j > 0) {
                    printf(" ");
                }
                printf("%d", i);
                j++;
            }
        }
        printf("\n\n");
    }

    return 0;
}