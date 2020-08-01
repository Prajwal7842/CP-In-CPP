#include <bits/stdc++.h>
using namespace std;

// Use adj matrix rep with this code.

int n, m;
vector<vector<int>> g;

const int inf = 1e18;

class MST {
public:
    int n;
    vector<int> parent;
    int weight = 0;
    MST(int nn) {
        this->n = nn;
        parent.assign(n+1, -1);
    }
    int minKey(vector<int>& key, vector<bool>& mstSet)
    {
        int min = inf, min_index;
        for (int i = 0; i <= n; i++)
            if (mstSet[i] == false && key[i] < min)
                min = key[i], min_index = i;
        return min_index;
    }
    void primMST()
    {
        vector<int> key(n+1, inf);
        vector<bool> mstSet(n+1, 0);
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < n; count++)
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int i = 0; i <= n; i++){
                if (g[u][i] && mstSet[i] == false && g[u][i] < key[i]){
                    parent[i] = u;
                    key[i] = g[u][i];
                }
            }
        }
    }
    int calWt() {
        weight = 0;
        for(int i = 1; i <= n; i ++) {
            weight += g[i][parent[i]];
        }
        return weight;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.assign(n + 1, vector<int>(n + 1, 0));
    return 0;
}