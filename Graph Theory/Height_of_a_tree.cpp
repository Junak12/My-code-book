#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123;
vector<int> adj[mx];
vector<int> height(mx, 0);

void dfs(int u, int par)
{
    for (auto d : adj[u])
    {
        if(d == par)continue;
        dfs(d, u);
        height[u] = max (height[u], height[d] + 1); // we know height of every leaf which is zero. That is why to calculate
                                                    // height we need to go bottom to top;
    }
}


int main()
{
    opt();
    int t;
    //cin >> t;
    t = 1;

    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        for (int i = 1; i <= n; ++i)
        {
            cout << i << " " << height[i] << endl;
        }

    }
}
