#include <bits/stdc++.h>

/* Insertion Sort
 * 
 * A função recebe um vetor v[0..n-1] e coloca os seus
 * elementos em ordem crescente. Para decrescente, basta
 * alterar o trecho v[j] < k para v[j] > k.
 *
 * O algoritmo é eficiente para ordenar poucos elementos.
 * 
 * Complexidade no pior caso: O(n^2)
 * */
void insertion_sort(int n, int v[n]) {
	int k, j;
	for (int i = 1; i < n; ++i) {
		k = v[i]; j = i - 1;
		while (j >= 0 && v[j] < k) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = k;
	}
}
