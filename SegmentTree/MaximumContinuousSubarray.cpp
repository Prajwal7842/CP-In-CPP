#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #include"Template.cpp"

/* 0 based Indexing */

const int inf = 1e18;


class Node
{
public:
    int sum, pref, suff, ans;
    Node() : sum(-inf), pref(-inf), suff(-inf), ans(-inf) {}
};

class SegmentTree
{
public:
    int n;
    vector<int> arr;
    vector<Node> tree;
    SegmentTree(int size)
    {
        n = size;
        arr.assign(n + 1, 0);
        tree.resize(4 * n + 1);
    }
    Node combine(const Node &l, const Node &r)
    {
        if (r.ans == (-inf))
        {
            Node res;
            res.ans = l.ans;
            res.sum = l.sum;
            res.pref = l.pref;
            res.suff = l.suff;
            return res;
        }
        else if (l.ans == (-inf))
        {
            Node res;
            res.ans = r.ans;
            res.sum = r.sum;
            res.pref = r.pref;
            res.suff = r.suff;
            return res;
        }
        Node res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }
    Node newNode(int val)
    {
        Node res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(-inf, val);
        return res;
    }
    void build(int curr, int left, int right)
    {
        if (left == right)
        {
            tree[curr] = newNode(arr[left]);
        }
        else
        {
            int mid = (left + right) / 2;
            build(curr << 1, left, mid);
            build(curr << 1 | 1, mid + 1, right);
            tree[curr] = combine(tree[curr << 1], tree[curr << 1 | 1]);
        }
    }
    Node query(int curr, int tl, int tr, int l, int r)
    {
        if (l > r)
            return newNode(-inf);
        if (l == tl && r == tr)
            return tree[curr];
        int tm = (tl + tr) / 2;
        return combine(query((curr * 2), tl, tm, l, min(r, tm)), query((curr * 2) + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree maxTree(n + 1);
    SegmentTree minTree(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x = arr[i - 1];
        maxTree.arr[i - 1] = x;
        minTree.arr[i - 1] = -x;
    }
    maxTree.build(1, 0, n - 1);
    minTree.build(1, 0, n - 1);
    int ans = -inf;
    for (int i = 1; i < n; i++)
    {
        Node left = maxTree.query(1, 0, n - 1, 0, i - 1);
    }
    cout << ans << endl;
}
