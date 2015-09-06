#include <bits/stdc++.h>

using namespace std;

/* Selection Sort
 *
 * A função recebe um vetor v[0..n-1] e o ordena de forma
 * crescente. 
 *
 * Para cada elemento v[i], com i de 0 a n - 1, 
 * busca o menor no vetor v[i..n-1] e realiza a troca.
 *
 * Invariantes:
 * a) v[0..i-1] está sempre ordenado;
 * b) v[min], no início de cada repetição do segundo for,
 * é sempre o menor elemento do vetor v[i..j-1];
 *
 * Tanto no pior quanto no melhor caso, a complexidade
 * é O(n^2).
 * */
void selection_sort(int n, int v[]) {
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

int main(void) {
	int v[6] = {6, 5, 4, 3, 2, 1};
	selection_sort(6, v);
	for (int i = 0; i < 6; ++i) cout<<v[i]<<"\n";
	return 0;
}
