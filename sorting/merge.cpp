#include <bits/stdc++.h>

using namespace std;

/* Merge
 *
 * Dados dois vetores, A[p..q] e A[q + 1..r], ambos em ordem crescente,
 * une-os em outro vetor A[p..r], mantendo a ordem crescente.
 *
 * Worst-case: O(n).
 * */
void merge(int *A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	for (int i = 0; i < n1; ++i) L[i] = A[p + i];
	for (int i = 0; i < n2; ++i) R[i] = A[q + 1 + i];	
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
		if (L[i] <= R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	while (i < n1) A[k++] = L[i++];
	while (j < n2) A[k++] = R[j++];
}

/* Merge Sort
 *
 * Segue a abordagem de dividir para conquistar, segmentando o vetor original
 * em dois, ordenando-os e unindo-os em seguida, usando a função merge definida
 * acima.
 *
 * Worst-case: O(n.lg(n))
 * */
void merge_sort(int *A, int p, int r) {
	if (p < r) {
		int q = (r + p) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main(void) {
	int A[] = {6, 5, 4, 3, 2, 1};
	merge_sort(A, 0, 5);
	for (int i = 0; i < 6; ++i) cout<<A[i]<<" ";
	cout<<endl;
}
