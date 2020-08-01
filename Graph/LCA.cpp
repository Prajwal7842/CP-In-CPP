#include<bits/stdc++.h>
using namespace std;

class LCA{
public:
    int n, k, timer;
    vector<vector<int>> g;
    vector<int> startTime, finishTime, depth;
    vector<vector<int>> table;
    int root;
    LCA(int n, int root) {
        this->n = n;
        this->root = root;
        k = ceil(log2(n));
        timer = 0;
        g.resize(n);
        startTime.resize(n);
        finishTime.resize(n);
        depth.resize(n);
        table.assign(n, vector<int>(k+1, -1));
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void preprocess(int level = 1) {
        dfs(this->root, -1, level);
    }
    void dfs(int src, int parent, int level) {
        depth[src] = level;
        startTime[src] = ++ timer;
        table[src][0] = parent;
        for(int i = 1; i <= k; i ++) {
            if(table[src][i-1] == -1)
                break;
            table[src][i] = table[table[src][i-1]][i-1];
        }
        for(auto v : g[src]) {
            if(v != parent) {
                dfs(v, src, level+1);
            }
        }
        finishTime[src] = ++timer;
    }
    int lca(int u, int v) {
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;
        for(int i = k; i >= 0; i --) {
            if(!isAncestor(table[u][i], v)) {
                u = table[u][i];
            }
        }
        return table[u][0];
    }
    bool isAncestor(int u, int v) {
        if(u < root) return true;
        return ((startTime[u] <= startTime[v]) && (finishTime[v] <= finishTime[u]));
    }
};


int32_t main() {
    int n;
    cin >> n;
    LCA graph(n+1, 1); // Number of Nodes, Root of Tree
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        graph.addEdge(u, v);
    }
    graph.preprocess();
    return 0;
}

