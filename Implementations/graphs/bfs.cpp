#include <bits/stdc++.h>

using namespace std;

/**
 * Breadth-first search.
 *
 * O(|V| + |E|)
 * */
void bfs(vector<int> * adj, int start) {
	queue<int> q;
	bool visited[7];

	q.push(start);

	while(!q.empty()) {
		int cur = q.front();

		for (int i = 0; i < adj[cur].size(); ++i) {
			if (!visited[adj[cur][i]]) {
				q.push(adj[cur][i]);
			}
		}
		
		q.pop();
		cout << cur << endl;
	}
}


int main(void) {

	vector<int> adj[7];	

	adj[1].push_back(2);
	adj[1].push_back(5);
	adj[2].push_back(6);
	adj[3].push_back(4);
	adj[5].push_back(3);

	bfs(adj,1);

	return 0;
}


