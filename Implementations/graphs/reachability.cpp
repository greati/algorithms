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

/* Depth-first Search customized to compute the start and
 * end times for each vertex in the search tree.
 * 
 **/
void DFS_visit(vector<int> * graph, int vertex, bool * & vis, int & time, int * * & startend, list<int> & vertex_dec_finish) {
	startend[vertex][0] = time++;
	vis[vertex] = true;
	for (int i = 0; i < graph[vertex].size(); ++i) {
		if (!vis[graph[vertex][i]])
			DFS_visit(graph, graph[vertex][i], vis, time, startend, vertex_dec_finish);
	}
	startend[vertex][1] = time++;
	vertex_dec_finish.push_front(vertex);
}

/* Uses DFS to compute the start and finish time of each vertex in
 * the DFS search tree.
 *
 **/
int * * compute_start_finish_time(vector<int> * graph, int start, int v, list<int> & vertex_dec_finish) {
	bool * vis = new bool[v + 1];
	for (int i = 1; i <= v; ++i)
		vis[i] = false;
	int time = 1;
	int * * startend = new int*[v + 1];
	for (int i = 1; i <= v; ++i)
		startend[i] = new int{0};
	for (int i = 1; i <= v; ++i)
		if (!vis[i])
			DFS_visit(graph,i,vis,time,startend, vertex_dec_finish);
	return startend;
}

/* Computes the transpose of the graph G = (V,E), defined as
 * GT = (V, E'), where E' = {(v,u) | (u,v) \in E)}.
 **/
vector<int> * transpose(vector<int> * graph, int v) {
	vector<int> * graphT = new vector<int>[v+1];
	for (int i = 1; i <= v; ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			graphT[graph[i][j]].push_back(i);
		}
	}
	return graphT;
}

void DFS_assign(vector<int> * graph, int vertex, int root_comp, bool * & assigned, vector<int> * & components) {
	assigned[vertex] = true;
	components[root_comp].push_back(vertex);
	for (int i = 0; i < graph[vertex].size(); ++i) {
		if (!assigned[graph[vertex][i]]) {
			DFS_assign(graph,graph[vertex][i],root_comp,assigned,components);
		}
	}
}

vector<int> * strongly_connected_components(vector<int> * graph, int v) {
	// Compute finish time and get vertices by decreasing finish time
	list<int> vertex_dec_finish;
	int * * times = compute_start_finish_time(graph, 1, v, vertex_dec_finish);	
	// Compute G's transpose
	vector<int> * graphT = transpose(graph,v);
	// Identify connected components
	vector<int> * components = new vector<int>[v+1];
	bool * assigned = new bool[v+1];
	for (int i = 1; i <= v; ++i) 
		assigned[i] = false;
	for (int i = 1; i <= v; ++i) {
		int cur_vertex = vertex_dec_finish.front();
		vertex_dec_finish.pop_front();
		if (!assigned[cur_vertex]) {
			DFS_assign(graphT,cur_vertex,cur_vertex,assigned,components);
		}
	}
	return components;	
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
	//vector<int> top_sort = topological_sort(graph,v);	
	//for (int i = 0; i < top_sort.size(); ++i)
	//	cout << top_sort[i] << endl;

	list<int> vertex_dec_finish;
	int * * times = compute_start_finish_time(graph, 1, v, vertex_dec_finish);	
	for (int i = 1; i <= v; ++i) {
			cout << vertex_dec_finish.front() << endl;
			vertex_dec_finish.pop_front();
			cout << "v" << i << ":" << times[i][0] << "/" << times[i][1] << endl;
	}

	vector<int> * components = strongly_connected_components(graph,v);
	for (int i = 1; i <= v; ++i) {
		for (int j = 0; j < components[i].size(); ++j) {
			cout << components[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}


