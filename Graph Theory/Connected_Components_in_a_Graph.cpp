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

void dfs(int u) {
	vis[u] = true;
	for (auto d : adj[u]) {
		if(!vis[d]) {
			dfs(d);
		}
	}
}

int main() {
	opt();
	int t;
	//cin >> t;
	t = 1;

	while(t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) { // for connectd component. if some of node are not visitd
			if(!vis[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}