#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int main() {
    opt();
    int V, E;
    //cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V); // Adjacency list storing {neighbor, weight}

    //cout << "Enter the edges (u v w) where w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Since it is an undirected graph
    }

    //cout << "Adjacency List with weights:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (auto neighbor : adj[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
    
    return 0;
}
