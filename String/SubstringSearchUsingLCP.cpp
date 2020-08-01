#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #include"Template.cpp"

class LCP {
public:
    string s;
    vector<int> suffix;
    vector<int> lcp;
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
    int compare(string& pat, int ind) {
        int sz = pat.size();
        int n = s.size();
        for(int i = 0; i < sz; i ++, ind ++) {
            if(ind == n) return 1;
            if(s[ind] > pat[i]) return -1;
            if(s[ind] < pat[i]) return 1;
        }
        return 0;
    }
    int isSubstring(string pat) {
        int l = 0, r = suffix.size();
        while(l <= r) {
            int mid = l + ((r - l)/2);
            int res = compare(pat, suffix[mid]);
            if(res == 0) {
                return mid;
            }
            if(res > 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};