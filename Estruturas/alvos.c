#include <stdio.h>

#define MAXN 100010

int n, m;
long long int r[MAXN];

int CALC_tiro(long long int val) {
    int ini = 1;
    int fim = n;

    if (val > r[n])
        return 0;

    while (ini < fim) {
        int meio = (ini + fim) / 2;

        if (r[meio] >= val) {
            fim = meio;
        } else {
            ini = meio + 1;
        }
    }
    return n + 1 - fim;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &r[i]);
        r[i] = r[i] * r[i];
    }

    long long int resp = 0;
    for (int i = 1; i <= m; i++) {
        long long int x, y;
        scanf("%lld %lld", &x, &y);

        resp += CALC_tiro(x * x + y * y);
    }

    printf("%lld\n", resp);
    return 0;
}
