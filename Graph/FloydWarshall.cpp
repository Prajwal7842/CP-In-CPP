#include<bits/stdc++.h>
using namespace std;

// dist[i][j] = 1e9 for unreachable nodes.
// dist[i][i] = 0

vector<vector<int>> g;
int n, m;

vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist = g;
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int T = 1; T <= t; T ++) {
        cin >> n >> m;
        g.assign(n+1, vector<int>(n+1, 1e9));
        for(int i = 1; i <= n; i ++) g[i][i] = 0;
        for(int i = 0; i < m; i ++) {
            int u, v, wt;
            cin >> u >> v >> wt;
            g[u][v] = wt;
            g[v][u] = wt;
        }
        vector<vector<int>> dist = floydWarshall();
    }
}