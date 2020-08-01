#include <bits/stdc++.h>
using namespace std;
#define int long long int

class DAG
{
public:
    int n, m;
    vector<vector<int>> g;
    DAG(int nn, int mm)
    {
        n = nn;
        m = mm;
        g.resize(n + 1);
    }
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
    }
    int dfs(int src, vector<int> &dp)
    {
        if (dp[src] != -1)
        {
            return dp[src];
        }
        int ans = 1;
        for (auto edge : g[src])
        {
            ans = max(ans, 1 + dfs(edge, dp));
        }
        dp[src] = ans;
        return ans;
    }
    int longestPath()
    {
        vector<int> dp(n + 1, -1);
        set<int> src;
        for (int i = 1; i <= n; i++)
            src.emplace(i);
        for (auto i : g)
        {
            for (auto j : i)
                src.erase(j);
        }
        assert(src.size() > 0);
        int ans = 0;
        for (auto i : src)
        {
            if (dp[i] == -1)
            {
                ans = max(ans, dfs(i, dp));
            }
        }
        return ans;
    }
};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    DAG dag(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dag.addEdge(u, v);
    }
    int ans = dag.longestPath();
    cout << ans - 1 << endl;
    return 0;
}