#include<bits/stdc++.h>
using namespace std;

/* Hamilton Path : A Path that visits each vertex only once. Uses BitMask + DP to find in O(2^n*n^2) */
/* Uses vertecies from 0 to n-1 */

class Graph {
public:
    vector<set<int>> g;
    int n, m;
    Graph(int nodes, int edges) {
        n = nodes;
        m = edges;
        g.resize(n);
    }
    void addEdge(int u, int v) {
        g[u].insert(v);
        g[v].insert(u);
    }
    bool isEdge(int from, int to) {
        return g[from].find(to) != g[from].end();
    }
    bool containsHamiltonPath() {
        vector<vector<bool>> dp(n, vector<bool>(1<<n, 0));
        for(int i = 0; i < n; i ++) {
            dp[i][1<<i] = 1;
        }
        int limit = 1<<n;
        for(int mask = 0; mask < limit; mask ++) {
            for(int j = 0; j < n; j ++) {
                if(mask&(1<<j)) {
                    for(int k = 0; k < n; k ++) {
                        if((mask&(1<<k)) && isEdge(k, j) && dp[k][mask^(1<<j)]) {
                            dp[j][mask] = 1;
                            break;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            if(dp[i][(1<<n)-1]) {
                return true;
            }
        }
        return false;
    }
    void Print(vector<vector<bool>>& dp) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < 1<<n; j ++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for(int i = 0; i < m; i ++) {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    bool res = g.containsHamiltonPath();
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}