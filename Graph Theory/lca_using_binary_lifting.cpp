#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123;
vector<int> adj[mx];
vector<vector<int>> dp(mx, vector<int>(17, 0));
vector<int> level(mx , 0);


void dfs(int u, int par) {
    dp[u][0] = par;
    if (par == 0) {
        level[u] = 0;
    }
    else {
        level[u] = level[par] + 1;
    }
    for (int i = 1; i < 17; ++i) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto d : adj[u]) {
        if (d == par) {
            continue;
        }
        dfs(d, u);
    }
}
int get_par(int node, int k) {
    for (int i = 16; i >=0; --i) {
        if ((k >> i) & 1) {
            node = dp[node][i];
        }
    }
}

int main() {
    opt();
    int t;
    cin >> t;

    while (t--) {
        int n , q;
        cin >> n >> q;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (level[a] > level[b]) {
                swap(a, b);
            }
            // a is less then b now;
            int k = level[b] - level[a];
            b = get_par(b, k);
            for (int i = 16; i >=0 ; --i) {
                if(dp[a][i] != dp[b][i]) {
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }
            cout << dp[a][0] << endl;
        }
    }
    return 0;
}

