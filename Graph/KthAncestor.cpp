#include <bits/stdc++.h>
using namespace std;


/*For Rooted Trees */

vector<vector<int>> g;
int n;

class Ancestor
{
public:
    vector<vector<int>> table;
    int height;
    void initialize(int n)
    {
        height = (int)ceil(log2(n));
        table.assign(n + 1, vector<int>(n + 1, -1));
    }
    void preprocess(int src, int parent)
    {
        fill(parent, src);
        for (auto i : g[src])
        {
            if (i != parent)
            {
                preprocess(i, src);
            }
        }
    }
    void fill(int u, int v)
    {
        table[v][0] = u;
        for (int i = 1; i <= height; i++)
        {
            table[v][i] = table[table[v][i - 1]][i - 1];
            if (table[v][i] == -1)
                break;
        }
    }
    int kthancestor(int V, int k)
    {
        for (int i = 0; i <= height; i++)
        {
            if (k & (1 << i))
            {
                V = table[V][i];
                if (V == -1)
                    break;
            }
        }
        return V;
    }
};
Ancestor asc;
