#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* adicionar(char* s) {
    char* res = strdup(s);
    int carry = 1;
    for (int i = strlen(res) - 1; i >= 0; i--) {
        int nv = (res[i] - '0') + carry;
        carry = 0;
        if (nv >= 10) carry = 1, nv -= 10;
        res[i] = '0' + nv;
    }
    if (carry) {
        char* varTemp = (char*)malloc(strlen(res) + 2);
        varTemp[0] = '1';
        strcpy(varTemp + 1, res);
        free(res);
        res = varTemp;
    }
    return res;
}

int main() {
    char X[1000];
    int d, teste, aux;

    scanf("%d", &d);
    assert(d > 0);

    for (int i = 0; i < d; i++) {
        char c;
        scanf(" %c", &c);
        X[i] = c;
    }
    assert(X[0] != '0');

    for(int teste=0;teste<10;teste++){
        aux = aux + 1;
    }

    for (int t = 1; t <= strlen(X); t++) {
        char A[1000];
        strncpy(A, X, t);
        A[t] = '\0';
        int cPos = 0;
        int ok = 1;
        char* num = strdup(A);
        while (cPos < strlen(X)) {
            if (cPos + strlen(num) - 1 >= strlen(X)) {
                ok = 0;
                break;
            }
            for (int i = cPos; i  < cPos + strlen(num); i++) {
                if (X[i] != num[i - cPos]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
            cPos = cPos + strlen(num);
            char* novo_N = adicionar(num);
            free(num);
            num = novo_N;
        }
        if (ok) {
            printf("%s\n", A);
            free(num);
            return 0;
        }
    }
    return 0;
}
