#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n;
vector<int> arr;

/* 
Query : Range Minimum
Update : Range Addition 
*/


struct Node
{
    int val, index;
    Node(int v, int i) : val(v), index(i) {}
    Node()
    {
        val = 1e9;
        index = -1;
    }
};

void Print(Node node)
{
    cout << node.val << " " << node.index << endl;
}

class SegmentTree
{
public:
    int n;
    vector<int> arr;
    vector<Node> tree;
    vector<int> lazy;
    vector<bool> islazy;
    SegmentTree(int size)
    {
        n = size;
        arr.assign(n + 1, 0);
        tree.resize(4 * n + 1, Node());
        lazy.assign(4 * n + 1, 0);
        islazy.assign(4 * n + 1, 0);
    }
    void build(int curr, int left, int right)
    {
        if (left == right)
        {
            tree[curr] = Node(arr[left], left);
            return;
        }
        int mid = (right + left) / 2;
        build(curr * 2, left, mid);
        build(curr * 2 + 1, mid + 1, right);
        combine(tree[curr], tree[curr * 2], tree[curr * 2 + 1]);
    }
    void combine(Node &res, Node &a, Node &b)
    {
        if (a.val == b.val)
        {
            res.val = b.val;
            res.index = b.index;
            return;
        }
        if (a.val < b.val)
        {
            res.val = a.val;
            res.index = a.index;
        }
        else
        {
            res.val = b.val;
            res.index = b.index;
        }
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
            lazy[curr] = val;
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
            lazyUpdate(curr, l, r);
        if (j < l || i > r)
            return Node();
        if (i <= l && r <= j)
        {
            return tree[curr];
        }
        int mid = (l + r) / 2;
        Node left = query(curr * 2, l, mid, i, j);
        Node right = query(curr * 2 + 1, mid + 1, r, i, j);
        Node node = Node();
        combine(node, left, right);
        return node;
    }
    Node query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
    void update(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }
    void Print()
    {
        for (int i = 0; i < 2 * n; i++)
        {
            cout << tree[i].val << " ";
        }
        cout << endl;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    SegmentTree tree(n);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> tree.arr[i];
    tree.build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        Node node = tree.query(1, n);
        // Print(node);
        int index = node.index;
        ans[index] = i;
        tree.update(index + 1, n, -i);
        tree.update(index, index, 1e18);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}