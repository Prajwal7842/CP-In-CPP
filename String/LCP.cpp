#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #include"Template.cpp"

/* LCP[i] = length of common prefix between adjacent suffixes.

To calculate common prefix between arbitrary suffixes, build Min Segment Tree on LCP array.
LCP = min(LCP[i], LCP[i+1] ... LCP[j])

*/

class LCP {
public:
    string s;
    vector<int> suffix;
    vector<int> lcp;
    vector<vector<int>> table;
    LCP(string st) {
        s = st;
    }        
    void CountSort(vector<int> &p, vector<int> &c)
    {
        int n = p.size();
        vector<int> cnt(n);
        for (auto x : c)
        {
            cnt[x]++;
        }
        vector<int> newp(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : p)
        {
            int i = c[x];
            newp[pos[i]] = x;
            pos[i]++;
        }
        p = newp;
    }
    void buildSuffix()
    {
        s += "$";
        int n = s.size();
        suffix.assign(n, 0);
        vector<int> c(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {s[i], i};
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
            suffix[i] = arr[i].second;
        c[suffix[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].first == arr[i - 1].first)
            {
                c[suffix[i]] = c[suffix[i - 1]];
            }
            else
            {
                c[suffix[i]] = c[suffix[i - 1]] + 1;
            }
        }
        int k = 0;
        while ((1 << k) < n)
        {
            for (int i = 0; i < n; i++)
            {
                suffix[i] = ((suffix[i] - (1 << k)) + n) % n;
            }
            CountSort(suffix, c);
            vector<int> newc(n, 0);
            for (int i = 1; i < n; i++)
            {
                pair<int, int> p1 = {c[suffix[i]], c[(suffix[i] + (1 << k)) % n]};
                pair<int, int> p2 = {c[suffix[i - 1]], c[(suffix[i - 1] + (1 << k)) % n]};
                if ((p1.first == p2.first) && (p1.second == p2.second))
                {
                    newc[suffix[i]] = newc[suffix[i - 1]];
                }
                else
                {
                    newc[suffix[i]] = newc[suffix[i - 1]] + 1;
                }
            }
            c = newc;
            k++;
        }
    }
    void buildLCP()
    {
        buildSuffix();
        int n = s.size(), k = 0;
        lcp.assign(n, 0);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            rank[suffix[i]] = i;

        for (int i = 0; i < n; i++, k ? k-- : 0)
        {
            if (rank[i] == n - 1)
            {
                k = 0;
                continue;
            }
            int j = suffix[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
        }
    }
    void buildRMQ() {
        int n = lcp.size();
        int size = 30;
        table.assign(n+10, vector<int>(size, 0));
        for (int i = 0; i < n; i++)
        {
            table[i][0] = lcp[i];
        }
        for (int j = 1; j <= size; j++)
        {
            for (int i = 0; (i + (1 << j)) <= n; i++)
            {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        if(l > r) swap(l, r);
        int index = (int)(log2(r - l + 1));
        return min(table[l][index], table[r - (1 << index) + 1][index]);
    }
};


void solve() {
    string s; cin >> s;
    LCP lcp(s);
    lcp.buildLCP();
    int ans = 0;
    for(int i = 1; i < lcp.lcp.size(); i ++) {
        ans += max(0LL, lcp.lcp[i] - lcp.lcp[i-1]);
    }
    cout << ans << endl;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

// To find common prefix of suffixes starting at i and j Use
/*
bool get(int l, int r) {
    int len = r - l + 1;
    int st = min(Index[l], Index[r]);
    int en = max(Index[l], Index[r]) - 1;
    int minn = lcp.query(st, en);
    return minn;
}
*/
