#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #include"Template.cpp"

struct Node
{
    int val, index;
    Node() : val(-1e9), index(-1) {}
    Node(int v, int i) : val(v), index(i) {}
};

class MaxSegmentTree
{
public:
    int n;
    vector<int> arr;
    vector<Node> tree;
    vector<int> lazy;
    vector<bool> islazy;
    MaxSegmentTree(int size)
    {
        n = size;
        arr.assign(n + 1, 0);
        tree.resize(4 * n + 1);
        lazy.assign(4 * n + 1, 0);
        islazy.assign(4 * n + 1, 0);
    }
    void combine(Node &res, Node &a, Node &b)
    {
        if (a.val == b.val)
        {
            res.val = a.val;
            res.index = min(a.index, b.index);
            return;
        }
        if (a.val < b.val)
        {
            res.val = b.val;
            res.index = b.index;
        }
        else
        {
            res.val = a.val;
            res.index = a.index;
        }
    }
    void build(int curr, int l, int r)
    {
        if (l == r)
        {
            tree[curr] = Node(arr[l], l);
            return;
        }
        int mid = (l + r) / 2;
        build(curr << 1, l, mid);
        build((curr << 1) | 1, mid + 1, r);
        combine(tree[curr], tree[curr << 1], tree[(curr << 1) | 1]);
    }

    void lazyUpdate(int curr, int l, int r)
    {
        if (l != r)
        {
            islazy[curr << 1] = 1;
            islazy[curr << 1 | 1] = 1;
            lazy[curr * 2] += lazy[curr];
            lazy[curr * 2 + 1] += lazy[curr];
        }
        tree[curr].val += lazy[curr];
        lazy[curr] = 0;
        islazy[curr] = 0;
    }

    void update(int curr, int l, int r, int i, int j, int val)
    {
        if (islazy[curr])
        {
            lazyUpdate(curr, l, r);
        }
        if (j < l || i > r || i > j)
        {
            return;
        }
        if (i <= l && r <= j)
        {
            islazy[curr] = 1;
            lazy[curr] += val;
            lazyUpdate(curr, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(curr * 2, l, mid, i, j, val);
        update(curr * 2 + 1, mid + 1, r, i, j, val);
        combine(tree[curr], tree[curr * 2], tree[curr * 2 + 1]);
    }
    Node query(int curr, int l, int r, int i, int j)
    {
        if (islazy[curr])
        {
            lazyUpdate(curr, l, r);
        }
        if (j < l || i > r)
            return Node();
        if (i <= l && r <= j)
        {
            return tree[curr];
        }
        int mid = (l + r) / 2;
        Node left = query(curr * 2, l, mid, i, j);
        Node right = query(curr * 2 + 1, mid + 1, r, i, j);
        Node val = Node();
        combine(val, left, right);
        return val;
    }
    Node query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
    void update(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }
};

int32_t main() {
    int n;
    vector<int> arr;
    cin >> n;
    arr.assign(n + 1, 0);
    MaxSegmentTree tree(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        tree.arr[i] = arr[i];
    }
    tree.build(1, 1, n);
    return 0;    
}