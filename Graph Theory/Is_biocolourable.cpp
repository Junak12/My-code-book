#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123;
vector<int> adj[mx];
vector<int> col(mx, -1);

bool is_bicolourable(int u) {
    col.assign(mx, -1);
    col[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto d : adj[cur]) {
            if (col[d] == -1) {  
                col[d] = 3 - col[cur];
                q.push(d);
            } else if (col[d] == col[cur]) { 
                return false;
            }
        }
    }
    return true;
}

int main() {
    opt();
    int t;
    t = 1;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool is_possible = true;
        for (int i = 0; i < n; ++i) {
            if (col[i] == -1) { 
                if (!is_bicolourable(i)) {
                    is_possible = false;
                    break;
                }
            }
        }
        
        if (is_possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
