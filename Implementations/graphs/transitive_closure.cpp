#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int adj[100][100];

	int n;

	cin >> n;

	int e;

	cin >> e;

	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}	

	// Reflexive closure
	for (int i = 1; i <= n; ++i)
		adj[i][i] = 1;

	// Transitive closure
	for (int m = 0; m < n - 2; ++m)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (adj[i][j])
					for (int k = 1; k <= n; ++k)
						if (adj[j][k])
							adj[i][k] = 1;
	// Computing the matrix of mutual reacheability
	int reach[100][100];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			reach[i][j] = adj[i][j] && adj[j][i];	

	// Print reacheabily matrix, just for checking
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << reach[i][j] << " ";
		cout << endl;
	}

	// Print components
	for (int i = 1; i <= n; ++i) {
		int mark = 0;
		for (int j = 1; j <= n; ++j) {
			cout << endl << "i = " << i << " j = " << j << endl;
			if (reach[i][j]) {
				if (i > j) break; // Takes only the right half
				mark = 1;
				cout << j << " ";	
			}
		}
		if (mark) cout << endl;
	}

	return 0;
}
