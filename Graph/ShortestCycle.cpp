#include <bits/stdc++.h>
using namespace std;

// Shortest Cycle In Undirected Unweighted Graph. Complexity : O(n*m)

class Graph
{
public:
    vector<vector<int>> g;
    int n, m;
    Graph(int size)
    {
        n = size;
        g.resize(n);
    }
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int shortestCycle()
    {
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            vector<int> dist(n, (int)(1e9));
            vector<int> par(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int child : g[x])
                {
                    if (dist[child] == (int)(1e9))
                    {
                        dist[child] = 1 + dist[x];
                        par[child] = x;
                        q.push(child);
                    }
                    else if (par[x] != child and par[child] != x)
                        ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};