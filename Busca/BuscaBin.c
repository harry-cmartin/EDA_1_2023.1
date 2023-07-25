#include <stdio.h>

#define less(A, B) (A < B)

int buscaBinaria(int *v, int begin, int end, int target) {
  int mid;

  int i = 0;
  while (end >= begin) {
    i++;
    mid = (begin + end) / 2;

    if (less(v[mid], target)) {
      begin = mid + 1;
    } else if (less(target, v[mid])) {
      end = mid - 1;
    } else {
      printf("Foram feitas %d iterações\n", i);
      return mid;
    }
  }

  printf("Foram feitas %d iterações\n", i);
  return -1;
}

int buscaBinariaRecursiva(int *v, int begin, int end, int target) {
  if (end < begin) {
    return -1;
  }

  int mid = (begin + end) / 2;
  if (less(v[mid], target)) {
    return buscaBinaria(v, mid + 1, end, target);
  } else if (less(target, v[mid])) {
    return buscaBinaria(v, begin, mid - 1, target);
  } else {
    return mid;
  }
}

int main() {
  int a[] = {1, 3, 5, 128, 300};
  int len = sizeof(a) / sizeof(int);

  int index = buscaBinaria(a, 0, len - 1, 128);
  printf("%d é o indice do elemento a ser buscado\n", index);
}