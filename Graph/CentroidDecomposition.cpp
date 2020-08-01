#include<bits/stdc++.h>
using namespace std;

// To get centroid tree call decomposeTree(root);


class Tree
{
public:
    int n, root;
    vector<vector<int>> tree;
    vector<vector<int>> cTree;
    vector<int> marked;
    vector<int> subtree;
    Tree(int size, int root)
    {
        n = size;
        this->root = root;
        tree.resize(n);
        cTree.resize(n);
        marked.assign(n, 0);
        subtree.resize(n);
    }
    void addEdge(int u, int v)
    {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    void getSubtreeSize(int src, int parent, int &nodes)
    {
        subtree[src] = 1;
        nodes++;
        for (auto edge : tree[src])
        {
            if (!marked[edge] && edge != parent)
            {
                getSubtreeSize(edge, src, nodes);
                subtree[src] += subtree[edge];
            }
        }
    }
    int getCentroid(int src, int parent, int nodes)
    {
        subtree[src] = 0;
        for (auto edge : tree[src])
        {
            if (edge == parent)
                continue;
            if (subtree[edge] > (nodes >> 1))
            {
                return getCentroid(edge, src, nodes);
            }
        }
        return src;
    }
    int getCentroid(int src)
    {
        int nodes = 0;
        getSubtreeSize(src, src, nodes);
        int centroid = getCentroid(src, src, nodes);
        marked[centroid] = 1;
        return centroid;
    }
    int decompose(int src)
    {
        int centroid = getCentroid(src);
        for (auto edge : tree[centroid])
        {
            if (!marked[edge])
            {
                int child = decompose(edge);
                cTree[centroid].push_back(child);
                cTree[child].push_back(centroid);
            }
        }
        return centroid;
    }
};

int32_t main() {
    int n; cin >> n;
    Tree tree(n+1, 1);
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        tree.addEdge(u, v);
    }
    int centroid = tree.decompose(1);
    cout << centroid;
    return 0;
}
