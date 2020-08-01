#include<bits/stdc++.h>
using namespace std;

/* Tree should be directed from parent to child */


class Tree {
public:
    vector<vector<int>> g;
    vector<int> startTime, endTime;
    int n, timer;
    Tree(int size) {
        n = size; timer = 0;
        g.resize(n);
        startTime.assign(n+1, 0);
        endTime.assign(n+1, 0);
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
    }
    void linearize(int src = 1) {
        startTime[src] = timer ++;
        for(auto e : g[src]) {
            linearize(e);
        }
        endTime[src] = timer-1;
    }
};