#include<bits/stdc++.h>
using namespace std;


// bridge returns pair of edges having cut edges

int n, m; 
vector<vector<int>> adj; 

vector<bool> visited;
vector<int> tin, low;
int timer;

set<pair<int, int>> bridge;

void IS_BRIDGE(int u, int v) {
    bridge.insert({u, v});
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void findBridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void printBridges() {
    for(auto i : bridge) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    findBridges();
    printBridges();
}
