#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e4 + 123;
vector<int> adj[mx];
vector<int> lvl(mx);

void bfs(int u) {
    lvl.assign(mx, -1);
    queue<int> q;
    lvl[u] = 0;
    q.push(u);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto d : adj[v] ) {
            if(lvl[d] == -1) {
                lvl[d] = lvl[v] + 1;
                q.push(d);
            }
        }
    }

}

int main(){
    opt();
    int t;
    cin >> t;
    //t = 1;

    while (t--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1);
        cout << lvl[n] << endl;
    }
}
