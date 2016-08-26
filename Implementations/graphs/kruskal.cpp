/*
Resposta ao problema 1152 do URI
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Implementation of union-find
*/
int parent[200001];
int rankh[200001];

void make_set(int n) {
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
		rankh[i] = 1;
	}
}

int find(int v) {
	if (parent[v] != v)
		parent[v] = find(parent[v]);
	return parent[v];
}

void join(int v, int u) {
	int pv = find(v);
	int pu = find(u);
	
	if (rankh[pv] > rankh[pu]) {
		parent[pu] = pv;
	} else if (rankh[pv] < rankh[pu]) {
		parent[pv] = pu;
	} else {
		parent[pu] = pv;
		++rankh[pv];	
	}	
}

int main(void) {
	
	priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>>> > edges;
	
	while (true) {
		
		int m, n, total_weight = 0;

		cin >> m >> n;

		if (m == 0) return 0;
		
		make_set(m);

		for (int i = 0; i < n; ++i) {
			int from, to, weight;
			cin >> from >> to >> weight;
			total_weight += weight;
			edges.push(make_pair(weight,make_pair(from,to)));
		}
			
		int min_weight = 0;
	
		while (!edges.empty()) {
			int u = edges.top().second.first;
			int v = edges.top().second.second;
			if (find(u) != find(v)) {
				join(u,v);
				min_weight += edges.top().first;	
			}	
			edges.pop();
		}	

		cout << total_weight - min_weight << endl;	
	}
	

	return 0;
}
