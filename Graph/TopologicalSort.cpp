#include<bits/stdc++.h>
using namespace std;

#define T int

vector<vector<T>> g;

void dfs(int src, vector<bool>& visited, vector<int>& ans) {
    visited[src] = 1;
    for(auto edge : g[src]) {
        if(!visited[edge]) {
            dfs(edge, visited, ans);
        }
    }
    ans.push_back(src);
}

vector<int> TopologicalSort(int n) {
    vector<int> ans;
    vector<bool> visited(n+1, 0);
    for(int i = 1; i <= n; i ++) {
        if(!visited[i]) {
            dfs(i, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> topoSort = TopologicalSort(n);
    return 0;
}
