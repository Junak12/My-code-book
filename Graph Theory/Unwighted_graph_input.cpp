#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int main() {
    int V, E; // V = number of vertices, E = number of edges
    //cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); // Adjacency list

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    //cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}
