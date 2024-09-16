#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123;
vector<int> adj[mx];
vector<bool> vis(mx, false);
vector<bool> recstack(mx, false);

bool is_cycle(int u, int parent) {
    vis[u] = true;
    recstack[u] = true;
    for (auto d : adj[u]) {
        if (!vis[d]) {
            if (is_cycle(d, u)) {
                return true;
            }
        }
        else if (recstack[d] && d != parent) {
            return true;
        }
    }
    recstack[u] = false;
    return false;
}

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while(t--) {
        int n, m;
        cin >> n >> m;
        
        // Reset the graph and visited status
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        fill(vis.begin(), vis.begin() + n, false);
        fill(recstack.begin(), recstack.begin() + n, false);
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool ok = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && is_cycle(i, -1)) {
                ok = true;
                break;
            }
        }
        
        if (ok) {
            cout << "Cycle is available" << endl;
        } else {
            cout << "No cycle is available" << endl;
        }
    }
}
