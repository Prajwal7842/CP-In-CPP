#include <bits/stdc++.h>
using namespace std;

// Longest Common Substring 

struct Node
{
    int len, link;
    vector<int> next;
    Node()
    {
        len = 0;
        link = -1;
        next.assign(26, 0);
    }
};

class SuffixAutomaton
{
public:
    int n;
    string s;
    vector<Node> st;
    int sz, last;
    SuffixAutomaton(string str)
    {
        s = str;
        n = str.size();
        st.resize(2 * n + 1);
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    void build()
    {
        for (auto i : s)
        {
            update(i);
        }
    }
    void update(char c)
    {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next[c - 'a'])
        {
            st[p].next[c - 'a'] = cur;
            p = st[p].link;
        }
        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[c - 'a'];
            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c - 'a'] == q)
                {
                    st[p].next[c - 'a'] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    int lcs(string s2, int &pos)
    {
        // pos -> for longest substring ending position
        int endpos = 0, ans = 0, len = 0, curr = 0;
        for (auto ch : s2)
        {
            endpos++;
            while (curr && !st[curr].next[ch - 'a'])
            {
                curr = st[curr].link;
                len = st[curr].len;
            }
            if (st[curr].next[ch - 'a'])
            {
                curr = st[curr].next[ch - 'a'];
                len++;
            }
            if (len > ans)
            {
                ans = len;
                pos = endpos;
            }
        }
        return ans;
    }
};


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    SuffixAutomaton sa(s1);
    sa.build();
    return 0;
}