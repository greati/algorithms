#include <bits/stdc++.h>

/* Selection Sort
 *
 * A função recebe um vetor v[0..n-1] e o ordena de forma
 * crescente. 
 *
 * Para cada elemento v[i], com i de 0 a n - 1, 
 * busca o menor no vetor v[i + 1..n-1] e realiza a troca.
 *
 * Tanto no pior quanto no melhor caso, a complexidade
 * é O(n^2).
 * */
void selection_sort(int n, int v[n]) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (v[min] > v[j]) min = j;
		}
		int tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
	}
}
