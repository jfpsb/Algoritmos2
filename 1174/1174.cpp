#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define INFINITO INT_MAX

class DisjointSets { // Classe de implementação da estrutura de dados “conjuntos disjuntos”

private:
	vector<int> DJ;
public:
	DisjointSets(int size) : DJ(size) {
		for (int u = 0; u < size; u++)
			DJ[u] = u;
	}
	int SET(int n) {
		if (DJ[n] == n)
			return n;
		else
			return DJ[n] = SET(DJ[n]);
	}
	int UNION(int n1, int n2) {
		return DJ[SET(n1)] = SET(n2);
	}
};

template <class PESO>
class Graph {
private:
	// V é um vetor de Vertices, E um vetor de Arestas
	int V, E;
	// ADJ vetor de nós adjacentes
	vector< vector<int> > adj;
	// WEIGHT é um vetor de pesos, nos respectivos nós.
	vector< vector<PESO> > weight;

	// Construtor que recebe como parâmetro o número de nós, adicionando um vetor de adj com número de nós
	// Vetor de WEIGHT com número de nós e Vetor de Vértices com o número de nós, e E (Arestas) vazio.
public:
	Graph(int nodes) : adj(nodes), weight(nodes),
		V(nodes), E(0)
	{ }

	//Retorna o número de vértices
	inline int getNodes() { return V; }
	// retorna o numero de arestas (E)
	inline int getEdges() { return E; }

	// conecta dois vértices (indices) "u" e "v" com peso W
	void addEdge(int u, int v, PESO w) {
		// inserindo no final o adjacente de u que é o v.
		adj[u].push_back(v);
		// inserindo peso no nó U. 
		weight[u].push_back(w);
		//conta o numero de arestas.
		E++;
	}
	// verifica se há conexão em dois vértices.
	bool hasEdge(int u, int v) {
		// numero de nós que ele aponta.
		int degree = adj[u].size();
		for (int i = 0; i < degree; i++) {
			// percorre todos os nós e verifica se existe uma ligação com o nó que foi passado como
			// parametro(v).

			if (adj[u][i] == v)
				return true;
		}

		return false;
	}
	//busca em largura
	// recebe o indice inicial para percorrer o grafo. 
	vector<int> bfs(int s) {
		// inicia o vetor  de verificação visitados como sendo false.
		vector<bool> visited(V, false);
		//fila de visitados.
		queue<int> q;
		// vetor de retorno de visitados
		vector<int> ret;

		//adiciona o nó inicial na fila
		q.push(s);
		// marca o nó inicial como visitado(true).
		visited[s] = true;

		// enquanto a pilha não for vazia
		while (!q.empty()) {
			// retira o primeiro elemento da fila.
			int u = q.front();
			// remove o elemento da fila.
			q.pop();

			// adiciona o visitado no vetor de retorno.
			ret.push_back(u);

			// percorre todas as arestas "i" do nó "u".
			for (int i = 0; i < adj[u].size(); i++) {
				// v recebe o índice do nó adjacente ao nó u
				int v = adj[u][i];
				// verifica se ja foi visitado, caso nao ;
				if (visited[v] == false) {
					// adiciona na fila de visitados
					q.push(v);
					// e marca ele como visitado
					visited[v] = true;
				}
			}
		}
		// retorna a sequencia de visitados pelo algoritmo BFS
		return ret;
	}

	// busca em profundidade
	vector<int> dfs(int s) {
		// marca todos como não visitados (false)
		vector<bool> visited(V, false);
		// pilha de visitados
		stack<int> st;
		// vetor de retorno de visitados
		vector<int> ret;

		st.push(s); // insere “s” na pilha
		visited[s] = true; // marca nó como visitado

//enquanto a pilha não estiver vazia
		while (!st.empty()) {
			// retira o último elemento inserido na pilha
			int u = st.top();
			st.pop();

			// adiciona o nó visitado no vetor de retorno
			ret.push_back(u);

			// busca por um vizinho não visitado
			for (int i = 0; i < adj[u].size(); i++) {
				// v recebe o índice do nó adjacente (adj) ao nó u
				int v = adj[u][i];
				if (visited[v] == false) {
					// se não foi visitado adiciona a pilha de visitados
					st.push(v);
					// marca como visitado
					visited[v] = true;
				}
			}
		}
		// retorna a sequência de visitados pelo algoritmo DFS
		return ret;
	}

	//algoritmo de dijkstra
	int Dijkstra(int s, int d) {
		vector<bool> visited(V, false); //inicia um vetor com os vértices não visitados

		vector<PESO> cost(V, INFINITO); //define o custo para todos os vertices como infinito
		cost[s] = 0; //o vertice inicial é definido com custo 0

		priority_queue< pair<PESO, int>,
			vector< pair<PESO, int> >,
			greater< pair<PESO, int> > > q;

		q.push(pair<PESO, int>(0, s)); //enfileira o vertice inicial

		while (!q.empty()) { //enquanto a fila não estiver vazia
			pair<PESO, int> p = q.front();
			q.pop(); //retira da fila
			int v = p.second;
			PESO costV = p.first;
			if (visited[v]) continue;

			if (v == d) return cost[d]; //se chegou ao vértice de destino para e retorna o custo total

			visited[v] = true; //marca o vertice como visitado

			for (int i = 0; i < adj[v].size(); i++) { // itera sobre o vetor de adjacencias
				int neigh = adj[v][i]; //define o vizinho
				if (cost[v] + weight[v][i] < cost[neigh]) { //se o custo do vértice atual mais o peso da aresta for menor que o custo do vizinho
					cost[neigh] = cost[v] + weight[v][i]; //o vizinho recebe o novo custo menor
					q.push(pair<PESO, int>(cost[neigh], neigh));
				}
			}
		}

	} //Dijkstra

	vector<int> topSort() {
		queue<int> q;
		vector<int> inDegree(V, 0);
		vector<int> ret;

		for (int u = 0; u < V; u++) {
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				// aresta u para v
				inDegree[v]++;
			}
		}

		for (int u = 0; u < V; u++) {
			if (inDegree[u] == 0)
				q.push(u);
		}

		//Enquanto a fila nao estiver vazia
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			ret.push_back(u);

			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				inDegree[v]--;
				if (inDegree[v] == 0)
					q.push(v);
			}
		}
		return ret;
	}//topsort

// Algoritmo de Kruskal
	PESO Kruskal() {
		PESO sum = 0;

		// Cria um vetor de arestas e seus respectivos pesos
		vector< pair<PESO, pair<int, int> > > edges;

		// Inicializa todas as arestas e seus pesos
		for (int u = 0; u < V; u++) {
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				pair<int, int> p(u, v);
				pair<PESO, pair<int, int> > e(weight[u][i], p);
				edges.push_back(e);
			}
		}

		// Ordena o vetor de arestas
		sort(edges.begin(), edges.end());

		/*
Inicializa estrutura conjuntos disjuntos
Utilizada para verificar se uma aresta já está na MST de forma rápida.
*/
		DisjointSets dj(V);

		for (int i = 0; i < edges.size(); i++) {
			pair<int, int> p = edges[i].second;
			int u = p.first;
			int v = p.second;
			// Se u e v estão em conjuntos distintos
			if (dj.SET(u) != dj.SET(v)) {
				//soma os pesos das arestas, representando o custo da MST
				sum += edges[i].first;

				// Coloca u e v no mesmo conjunto
				dj.UNION(u, v);
				//cout << u << " para " << v << " = " << edges[i].first << endl;
			}
		}

		return sum;
	} //Kruskal

	PESO Prim() {
		vector<bool> visited(V, false); //inicia um vetor com os vértices não visitados
		vector<PESO> cost(V, INFINITO); //define o custo para todos os vertices como infinito


		PESO sum = 0;
		cost[0] = 0;

		priority_queue< pair<PESO, int>,
			vector< pair<PESO, int> >,
			greater< pair<PESO, int> > > q;

		q.push(pair<PESO, int>(0/*cost*/, 0/*node*/));

		//Enquanto a Fila não estiver vazia
		while (!q.empty()) {
			pair<PESO, int> p = q.top(); //Recupera o próximo da fila
			q.pop(); //Remove da fila
			int v = p.second;
			PESO costV = p.first;
			if (visited[v]) continue; //Caso tenha sido visitado: ignore-o

			cout << "v = " << v << endl;

			visited[v] = true; //Marca como visitado
			sum += cost[v]; //Incrementa o Custo Total

			for (int i = 0; i < adj[v].size(); i++) {
				int neigh = adj[v][i];
				if (weight[v][i] < cost[neigh]) {
					cost[neigh] = weight[v][i];
					q.push(pair<PESO, int>(cost[neigh], neigh));
				}
			}


		} //while(q)
		return sum;
	}//Prim
};

int main()
{
	int casos, m, n, a = 0;

	cin >> casos;

	for (int i = 0; i < casos; i++) {

		cin >> m;
		cin >> n;
		a = 0;
		map<string, int> mapa;
		Graph<int> grafo(m);

		for (int j = 0; j < n; j++) {
			string c1, c2;
			int peso, u, v, p;

			cin >> c1 >> c2 >> peso;

			if (mapa.find(c1) == mapa.end()) {
				mapa[c1] = a++;
			}

			if (mapa.find(c2) == mapa.end()) {
				mapa[c2] = a++;
			}

			u = mapa[c1];
			v = mapa[c2];

			grafo.addEdge(u, v, peso);
		}

		cout << grafo.Kruskal() << endl;
	}

	return 0;
}
