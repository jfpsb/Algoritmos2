#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>

using namespace std;
template <class PESO>

class Graph {
private:
	int V, E;
	vector< vector<int> > adj;
	vector< vector<PESO> > weight;

	void dfsVisit(int s, vector<bool>& visited) {
		visited[s] = true;
		cout << "dfs " << s << endl;

		for (int i = 0; i < adj[s].size(); i++) {
			int v = adj[s][i];
			if (visited[v] == false) {
				dfsVisit(v, visited);
			}
		}
	}


public:
	Graph(int nodes) : adj(nodes), weight(nodes) {
		V = nodes;
		E = 0;
	}
	inline int getNodes() { return V; }
	inline int getEdges() { return E; }

	void addEdge(int u, int v, PESO w) {
		adj[u].push_back(v);
		weight[u].push_back(w);
	}

	bool hasEdge(int u, int v) {
		int degree = adj[u].size();
		for (int i = 0; i < degree; i++) {
			if (adj[u][i] == v)
				return true;
		}
		return false;
	}

	void bfs(int s) {
		vector<bool> visited(V, false);
		queue<int> q;

		q.push(s);
		visited[s] = true;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			cout << "bfs " << u << endl;

			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (visited[v] == false) {
					q.push(v);
					visited[v] = true;
				}
			}
		}
	}


	void dfs(int s) {
		vector<bool> visited(V, false);
		dfsVisit(s, visited);
	}

	int dijkstra(int node, int T) {
		vector<int> cost(V, INT_MAX);
		vector<bool> visited(V, false);
		cost[node] = 0;

		while (true) {
			//escolher node de trabalho
			//menor cost entre nao-visitados
			int wNode = -1;

			for (int i = 0; i < V; i++) {
				if (!visited[i]) {
					if (wNode == -1 || cost[i] < cost[wNode]) {
						wNode = i;
					}
				}
			}

			if (wNode == -1 || cost[wNode] == INT_MAX)
				break;

			visited[wNode] = true;
			for (int i = 0; i < adj[wNode].size(); i++) {
				int v = adj[wNode][i];

				if (cost[wNode] + weight[wNode][i] < cost[v])
					cost[v] = cost[wNode] + weight[wNode][i];
			}
		}

		int ratos = 0;
		for (int i = 0; i < cost.size(); i++) {
			if (cost[i] <= T)
				ratos++;
		}

		return ratos;
	}
};


int main() {

	int t;

	cin >> t;

	while (t--) {
		int nodes, edges, exitCell, T;

		cin >> nodes;
		Graph<int> g(nodes + 1);
		cin >> exitCell;
		cin >> T;
		cin >> edges;

		while (edges--) {
			int u, v, w;
			cin >> u >> v >> w;
			g.addEdge(v, u, w);
		}

		cout << g.dijkstra(exitCell, T) << endl;

		if (t)
			cout << endl;
	}
}