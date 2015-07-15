#include <bits/stdc++.h>

using namespace std;

long long countSplitMerge(int A[], int p, int q, int r) {
	int nl = q - p + 1;
	int nr = r - q;
	int L[nl], R[nr];	
	for (int i = 0; i < nl; ++i) L[i] = A[p + i];
	for (int i = 0; i < nr; ++i) R[i] = A[q + 1 + i];
	int i = 0, j = 0, k = p; 
	long long count = 0;
	while (i < nl && j < nr) {
		if (L[i] <= R[j]) {
			A[k++] = L[i++];
		} else {
			A[k++] = R[j++];
			// compute inversions
			count += nl - i;	
		}
	}
	while (i < nl) A[k++] = L[i++];
	while (j < nr) A[k++] = R[j++];
	return count;
}

long long count(int A[], int p, int r) {
	long long c = 0;
	if (p < r) {
		int q = (p + r) / 2;
		c += count(A, p, q);
		c += count(A, q + 1, r);
		c += countSplitMerge(A, p, q, r);
	}
	return c;
}
