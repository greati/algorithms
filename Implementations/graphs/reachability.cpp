#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> * graph, int start, int * & parent) {
	queue<int> q;
	char color[100];
	memset(color,'w',sizeof(color)/sizeof(char));
	q.push(start);	
	color[start] = 'g';
	while(!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < graph[cur].size(); ++i) {
			if (color[graph[cur][i]] == 'w') {
				color[graph[cur][i]] = 'g';
				q.push(graph[cur][i]);
				parent[graph[cur][i]] = cur;
			}
		}
		color[cur] = 'b';
		q.pop();
	}
}

bool reachable(vector<int> * graph, int from, int to) {

	if (from == to) return true;

	int * parent = new int[100];

	for (int i = 0; i < 100; ++i)
		parent[i] = -1;

	bfs(graph,from,parent);

	return parent[to] != -1;
}

vector<int> path(vector<int> * graph, int from, int to) {

	int * parent = new int[100];

	for (int i = 0; i < 100; ++i)
		parent[i] = -1;

	bfs(graph,from,parent);
	
	vector<int> path;

	if (parent[to] != -1) {
		int i = to;
		while (i != -1) {
			path.push_back(i);
			i = parent[i];	
		}
	}
	
	return path;
}

bool connected(vector<int> * graph, int v) {
	int * parent = new int[100];

	for (int i = 0; i < 100; ++i)
		parent[i] = -1;

	bfs(graph,1,parent);

	for (int i = 2; i <= v; ++i) {
		if (parent[i] == -1) {
			cout << i << endl;
			return false;
		}
	} 

	return true;
}

bool cycle(vector<int> * graph, int v) {
	char color[100];
	
	memset(color,'w',sizeof(color)/sizeof(char));
	
	for (int k = 1; k <= v; ++k) {
		
		if (color[k] != 'w') continue;

		queue<int> q;

		q.push(k);

		color[k] = 'g';

		while (!q.empty()) {
			int cur = q.front();

			for (int i = 0; i < graph[cur].size(); ++i) {
				int adj = graph[cur][i];
				if (color[adj] == 'g' || color[adj] == 'b')
					return true;
				if (color[adj] == 'w') {
					color[adj] = 'g';
					q.push(adj);		
				}		
			}

			color[cur] = 'b';
			q.pop();	
		}
	}
	return false;
}

vector<int> topological_sort(vector<int> * graph, int v) {
	queue<int> q;
	vector<int> ordering;
	int indegree[v];

	// Counting in degrees
	for (int i = 1; i <= v; ++i) {
		indegree[i] = 0;
		for (int j = 0; j < graph[i].size(); ++j) {
			indegree[graph[i][j]]++;	
		}
	}

	for (int i = 1; i <= v; ++i)
		cout << indegree[i] << endl;

	// Putting in the queue the starting elements
	for (int i = 1; i <= v; ++i)
		if (indegree[i] == 0)
			q.push(i);

	// Processing
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < graph[cur].size(); ++i) {
			if(--indegree[graph[cur][i]] == 0)
				q.push(graph[cur][i]);
		}
		ordering.push_back(cur);
		q.pop();
	}

	return ordering;
}

int main(void) {
	
	vector<int> graph[100];

	int v, e;

	cout << "Number of vertices: ";
	cin >> v;

	cout << "Number of edges: ";
	cin >> e;

	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);	
	}

	//cout << cycle(graph, v) << endl;
	//cout << connected(graph, v) << endl;

	vector<int> top_sort = topological_sort(graph,v);	
	for (int i = 0; i < top_sort.size(); ++i)
		cout << top_sort[i] << endl;

	return 0;
}


