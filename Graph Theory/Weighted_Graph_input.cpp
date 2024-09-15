#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

struct edge {
    int to, wt;
};


int main(){
    opt();
    int t;
    cin >> t;
    int case_num = 0;

    while (t--){
        case_num++;
        int n, m;
        cin >> n >> m;
        vector<vector<edge>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    return 0;
}