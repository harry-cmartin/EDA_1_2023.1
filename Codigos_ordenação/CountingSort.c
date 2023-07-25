#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A, B) ((A) < (B))

void countsort(Item *v, int begin, int end) {
  int R = 0;
  for (int i = begin; i <= end; i++) {
    if (v[i] > R) {
      R = v[i];
    }
  }
  R += 2;

  int *count = calloc(sizeof(int), R);
  for (int i = begin; i <= end; i++) {
    count[v[i] + 1]++;
  }

  for (int i = 1; i < R; i++) {
    count[i] += count[i - 1];
  }

  Item *aux = malloc(sizeof(Item) * (end - begin + 1));
  for (int i = begin; i <= end; i++) {
    aux[count[v[i]]] = v[i];
    count[v[i]]++;
  }

  for (int i = begin; i <= end; i++) {
    v[i] = aux[i - begin];
  }
  free(count);
  free(aux);
}

int main() {
  int sla[] = {1, 23, 43, 312, 321, 5, 42, 1};
  int n = sizeof(sla) / sizeof(int);

  countsort(sla, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", sla[i]);
  }
}