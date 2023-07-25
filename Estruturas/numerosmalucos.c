#include <stdio.h>
#include <stdlib.h>
#define les(a, b) (a <= b)

int * merge2(int *vet1, int A1, int B1, int *vet2, int A2, int B2) {

	int *vet3 = malloc(sizeof(int) * ((B1 - A1 + 1) + (B2 - A2 + 1)));
	int vet3i = 0, vet1i = A1, vet2i = A2;

	while (les(vet1i, B1) && les(vet2i, B2)) {
		if (les(vet1[vet1i], vet2[vet2i]))
			vet3[vet3i++] = vet1[vet1i++];
		else
			vet3[vet3i++] = vet2[vet2i++];
	}
	while (les(vet1i, B1))
		vet3[vet3i++] = vet1[vet1i++];

	while (les(vet2i, B2))
		vet3[vet3i++] = vet2[vet2i++];
	return vet3;
}

void merge(int *vet, int a, int b, int c) {

	int *vet2 = malloc(sizeof(int) * (c - a + 1));
	int l = 0, i = a, j = b+1;

	while (les(i, b) && les(j, c)) {
		if (les(vet[i], vet[j]))
			vet2[l++] = vet[i++];
		else
			vet2[l++] = vet[j++];
	}
	while (les(i, b))
		vet2[l++] = vet[i++];

	while (les(j, c))
		vet2[l++] = vet[j++];
	l = 0;

	for (int i = a; i <= c; i++)
		vet[i] = vet2[l++];
	free(vet2);
}

void MergeSort(int *vet, int a, int b) {

	if (a >= b) return;
	int r = a + (b - a) / 2;
	MergeSort(vet, a, r);
	MergeSort(vet, r+1, b);
	merge(vet, a, r, b);
}

int buscabinaria(int *vet, int a, int b, int n) {
	if (a <= b) {
		int k = a + (b - a) / 2;
		if (vet[k] == n)
			return k;
		else if (vet[k] > n)
			return buscabinaria(vet,a, k-1, n);
		else
			return buscabinaria(vet, k+1, b, n);
	}

	return -1;
}

int clean(int *vet, int a, int b) {
	int j = a;

	for (int i = 1; i <= b; i++) {
		if (vet[i] != vet[j])
			vet[++j] = vet[i];
	}
	return j;

}

int main() {
	int n, *x, *nmu, j = -1;
	scanf("%i", &n);

	x = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%i", &x[i]);

	MergeSort(x, 0, n-1);
	int b = clean(x, 0, n-1);

	if (b % 2 == 0)
		x[++b] = 1000000000;
	nmu = malloc(sizeof(int) * (b / 2 + 1));

	for (int i = 0; i < b; i += 2) {
		nmu[++j] = x[i] + x[i+1];
		if (buscabinaria(x, 0, b, nmu[j]) != -1)
			j--;
	}
	int *fx = merge2(x, 0, b, nmu, 0, j); free(nmu); free(x);

	for (int i = 0; i <= b+j+1; i += 4)
		printf("%i\n", fx[i]);


	printf("Elementos: %i\n", b+j+2);
	
}
