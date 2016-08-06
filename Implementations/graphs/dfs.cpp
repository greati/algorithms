#include <bits/stdc++.h>

using namespace std;

/**
 * Depth-first search.
 *
 * O(|V| + |E|)
 * */
void dfsR(vector<int> * adj, int cur, bool * & vis) {
	vis[cur] = true;
	cout << cur << endl;
	for (int i = 0; i < adj[cur].size(); ++i)
		if (!vis[adj[cur][i]])
			dfsR(adj,adj[cur][i], vis);
}

/**
 * Auxiliar for DFS.
 *
 * O(|V| + |E|)
 * */
void dfs(vector<int> * adj, int start) {
	bool * vis = new bool[7];
	dfsR(adj,start,vis);
}


int main(void) {

	vector<int> adj[7];	

	adj[1].push_back(2);
	adj[1].push_back(5);
	adj[2].push_back(6);
	adj[3].push_back(4);
	adj[5].push_back(3);

	dfs(adj,1);

	return 0;
}


