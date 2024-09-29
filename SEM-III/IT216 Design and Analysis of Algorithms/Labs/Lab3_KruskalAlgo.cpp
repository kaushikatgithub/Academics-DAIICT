#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
	int u;
	int v;
	int weight;
};

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n) {
		parent.resize(n);
		rank.resize(n);
		for(int i = 0 ; i < n ; ++i) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	// Find function to find parent of k	
	int find(int k) {
		if(parent[k] == k) {
			return k;
		}
		
		// Path compression recursive logic
		int root = find(parent[k]);
		parent[k] = root;

		return root;
	}

	// Union operation
	void Union(int u, int v) {
		int parent_u = find(u);
		int parent_v = find(v);

		if(rank[parent_u] < rank[parent_v]) {
			parent[parent_u] = parent_v;
		}else if(rank[parent_v] < rank[parent_u]) {
			parent[parent_u] = parent_v;
		}else {
			parent[parent_u] = parent_v;
			rank[parent_v]++;
		}
	}
};

bool compare(Edge &e1, Edge &e2) {
	return e1.weight <= e2.weight;
}

int MST(vector<Edge> &graph, int n, vector<Edge>& mst) {
	sort(graph.begin(), graph.end(), compare);
	DisjointSet dsu(n);
	int ans = 0;
	for(auto e : graph) {
		int parent_u = dsu.find(e.u);
		int parent_v = dsu.find(e.v);

		if(parent_u != parent_v) {
			dsu.Union(parent_u, parent_v);
			ans += e.weight;
			mst.push_back(e);
		}
	}

	return ans;
}

int main() {
	int n = 6;
	vector<Edge> graph = {{0, 1, 2}, {0, 3, 1}, {0, 4, 4}, {1, 2, 3}, {1, 3, 3}, {1, 5, 7}, {2, 3, 5}, {2, 5, 8}, {3, 4, 9}};
	vector<Edge> mst;	
	int w = MST(graph, n, mst);
	
	cout << "Minimum Spanning Tree : Kruskal's Algorithm :\n";
	for(auto e : mst) {
		cout << e.u << " - " << e.v << ", Weight : " << e.weight << "\n";
	}
	cout << "Minimum Weight : " << w << "\n";
	return 0;
}

