#include <bits/stdc++.h>

using namespace std;

/* Insertion Sort
 * 
 * A função recebe um vetor v[0..n-1] e coloca os seus
 * elementos em ordem crescente. Para decrescente, basta
 * alterar o trecho v[j] > k para v[j] < k.
 *
 * O algoritmo é eficiente para ordenar poucos elementos.
 *
 * Invariante: o vetor v[0..i-1] está sempre ordenado.
 *
 * A ideia é inserir um novo elemento (k) no ponto
 * correto do vetor já ordenado.
 *
 * Complexidade no pior caso: O(n^2)
 * */
void insertion_sort(int n, int v[]) {
	int k, j;
	for (int i = 1; i < n; ++i) {
		k = v[i]; j = i - 1;
		while (j >= 0 && v[j] > k) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = k;
	}
}

int main(void) {
	int v[6] = {6, 5, 4, 3, 2, 1};
	insertion_sort(6, v);
	for (int i = 0; i < 6; ++i) cout<<v[i]<<"\n";
	return 0;
}
