#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

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

    int find(int k) {
        if(parent[k] == k) {
            return k;
        }
        
        // Path compression
        int res = find(parent[k]);
        parent[k] = res;

        return res;
    }

    void Union(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);

        if(rank[par_u] < rank[par_v]) {

            parent[par_u] = par_v;
        
        }else if(rank[v] < rank[u]) {

            parent[par_v] = par_u;

        }else {

            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

// Graph
/*              5
            3 ----- 2
        9  /|\      |\  8
          / | \ 3   | \
         4 1|  --- 3|  5
          \ |     \ | /
        4  \|   2  \|/  7
            0 ----- 1
*/

struct Edge {
    int u;
    int v;
    int weight;
};

bool compare(Edge &e1, Edge &e2) {
    return e1.weight <= e2.weight;
}


vector<Edge> kruskalsAlgorithm(vector<Edge> &graph, int n) {
    sort(graph.begin(), graph.end(), compare);
    DisjointSet dsu(n);
    vector<Edge> mst;
    for(auto e : graph) {
        int par_u = dsu.find(e.u);
        int par_v = dsu.find(e.v);

        if(par_u != par_v) {
            dsu.Union(par_u, par_v);
            mst.push_back(e);
        }
    }
    return mst;
}

int main() {
    vector<Edge> graph = {
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 5},
        {3, 4, 9},
        {0, 3, 1},
        {0, 4, 4},
        {1, 3, 3},
        {1, 5, 7},
        {2, 5, 8},
    };

    int n = 6;
    vector<Edge> mst = kruskalsAlgorithm(graph, n);

    cout << "Minimum  Spanning Tree Edges : \n";
    for(auto e : mst) {
        cout << e.u << " - " << e.v << ", Weight : " << e.weight << "\n";
    }
    return 0;
}
