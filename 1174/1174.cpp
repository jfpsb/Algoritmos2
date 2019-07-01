#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define INFINITO INT_MAX

class DisjointSets { // Classe de implementa��o da estrutura de dados �conjuntos disjuntos�

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
	// V � um vetor de Vertices, E um vetor de Arestas
	int V, E;
	// ADJ vetor de n�s adjacentes
	vector< vector<int> > adj;
	// WEIGHT � um vetor de pesos, nos respectivos n�s.
	vector< vector<PESO> > weight;

	// Construtor que recebe como par�metro o n�mero de n�s, adicionando um vetor de adj com n�mero de n�s
	// Vetor de WEIGHT com n�mero de n�s e Vetor de V�rtices com o n�mero de n�s, e E (Arestas) vazio.
public:
	Graph(int nodes) : adj(nodes), weight(nodes),
		V(nodes), E(0)
	{ }

	//Retorna o n�mero de v�rtices
	inline int getNodes() { return V; }
	// retorna o numero de arestas (E)
	inline int getEdges() { return E; }

	// conecta dois v�rtices (indices) "u" e "v" com peso W
	void addEdge(int u, int v, PESO w) {
		// inserindo no final o adjacente de u que � o v.
		adj[u].push_back(v);
		// inserindo peso no n� U. 
		weight[u].push_back(w);
		//conta o numero de arestas.
		E++;
	}
	// verifica se h� conex�o em dois v�rtices.
	bool hasEdge(int u, int v) {
		// numero de n�s que ele aponta.
		int degree = adj[u].size();
		for (int i = 0; i < degree; i++) {
			// percorre todos os n�s e verifica se existe uma liga��o com o n� que foi passado como
			// parametro(v).

			if (adj[u][i] == v)
				return true;
		}

		return false;
	}
	//busca em largura
	// recebe o indice inicial para percorrer o grafo. 
	vector<int> bfs(int s) {
		// inicia o vetor  de verifica��o visitados como sendo false.
		vector<bool> visited(V, false);
		//fila de visitados.
		queue<int> q;
		// vetor de retorno de visitados
		vector<int> ret;

		//adiciona o n� inicial na fila
		q.push(s);
		// marca o n� inicial como visitado(true).
		visited[s] = true;

		// enquanto a pilha n�o for vazia
		while (!q.empty()) {
			// retira o primeiro elemento da fila.
			int u = q.front();
			// remove o elemento da fila.
			q.pop();

			// adiciona o visitado no vetor de retorno.
			ret.push_back(u);

			// percorre todas as arestas "i" do n� "u".
			for (int i = 0; i < adj[u].size(); i++) {
				// v recebe o �ndice do n� adjacente ao n� u
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
		// marca todos como n�o visitados (false)
		vector<bool> visited(V, false);
		// pilha de visitados
		stack<int> st;
		// vetor de retorno de visitados
		vector<int> ret;

		st.push(s); // insere �s� na pilha
		visited[s] = true; // marca n� como visitado

//enquanto a pilha n�o estiver vazia
		while (!st.empty()) {
			// retira o �ltimo elemento inserido na pilha
			int u = st.top();
			st.pop();

			// adiciona o n� visitado no vetor de retorno
			ret.push_back(u);

			// busca por um vizinho n�o visitado
			for (int i = 0; i < adj[u].size(); i++) {
				// v recebe o �ndice do n� adjacente (adj) ao n� u
				int v = adj[u][i];
				if (visited[v] == false) {
					// se n�o foi visitado adiciona a pilha de visitados
					st.push(v);
					// marca como visitado
					visited[v] = true;
				}
			}
		}
		// retorna a sequ�ncia de visitados pelo algoritmo DFS
		return ret;
	}

	//algoritmo de dijkstra
	int Dijkstra(int s, int d) {
		vector<bool> visited(V, false); //inicia um vetor com os v�rtices n�o visitados

		vector<PESO> cost(V, INFINITO); //define o custo para todos os vertices como infinito
		cost[s] = 0; //o vertice inicial � definido com custo 0

		priority_queue< pair<PESO, int>,
			vector< pair<PESO, int> >,
			greater< pair<PESO, int> > > q;

		q.push(pair<PESO, int>(0, s)); //enfileira o vertice inicial

		while (!q.empty()) { //enquanto a fila n�o estiver vazia
			pair<PESO, int> p = q.front();
			q.pop(); //retira da fila
			int v = p.second;
			PESO costV = p.first;
			if (visited[v]) continue;

			if (v == d) return cost[d]; //se chegou ao v�rtice de destino para e retorna o custo total

			visited[v] = true; //marca o vertice como visitado

			for (int i = 0; i < adj[v].size(); i++) { // itera sobre o vetor de adjacencias
				int neigh = adj[v][i]; //define o vizinho
				if (cost[v] + weight[v][i] < cost[neigh]) { //se o custo do v�rtice atual mais o peso da aresta for menor que o custo do vizinho
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
Utilizada para verificar se uma aresta j� est� na MST de forma r�pida.
*/
		DisjointSets dj(V);

		for (int i = 0; i < edges.size(); i++) {
			pair<int, int> p = edges[i].second;
			int u = p.first;
			int v = p.second;
			// Se u e v est�o em conjuntos distintos
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
		vector<bool> visited(V, false); //inicia um vetor com os v�rtices n�o visitados
		vector<PESO> cost(V, INFINITO); //define o custo para todos os vertices como infinito


		PESO sum = 0;
		cost[0] = 0;

		priority_queue< pair<PESO, int>,
			vector< pair<PESO, int> >,
			greater< pair<PESO, int> > > q;

		q.push(pair<PESO, int>(0/*cost*/, 0/*node*/));

		//Enquanto a Fila n�o estiver vazia
		while (!q.empty()) {
			pair<PESO, int> p = q.top(); //Recupera o pr�ximo da fila
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
