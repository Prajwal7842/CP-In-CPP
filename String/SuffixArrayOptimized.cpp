//Tested
#include<bits/stdc++.h>
using namespace std;

// Build SuffixArray In O(n log(n)) time

void CountSort(vector<int>& p, vector<int>& c) {
    int n = p.size();
    vector<int> cnt(n);
    for(auto x : c) {
        cnt[x] ++;
    }
    vector<int> newp(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; i ++) {
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p) {
        int i = c[x];
        newp[pos[i]] = x;
        pos[i] ++;
    }
    p = newp;
}

vector<int> buildSuffix(string s) {
    s += "$";
    int n = s.size();
    vector<int> suffix(n, 0);
    vector<int> c(n, 0);
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i ++) arr[i] = {s[i], i};
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i ++) suffix[i] = arr[i].second;
    c[suffix[0]] = 0;
    for(int i = 1; i < n; i ++) {
        if(arr[i].first == arr[i-1].first) {
            c[suffix[i]] = c[suffix[i - 1]];
        }
        else {
            c[suffix[i]] = c[suffix[i-1]] + 1;
        }
    }
    int k = 0;
    while((1 << k) < n) {
        for(int i = 0; i < n; i ++) {
            suffix[i] = ((suffix[i] - (1 << k)) + n) % n;
        }
        CountSort(suffix, c);
        vector<int> newc(n, 0);
        for (int i = 1; i < n; i++)
        {
            pair<int, int> p1 = {c[suffix[i]], c[(suffix[i] + (1 << k))%n]};
            pair<int, int> p2 = {c[suffix[i-1]], c[(suffix[i-1] + (1 << k))%n]};
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
        k ++;        
    }
    return suffix;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> suffix = buildSuffix(s);
    for(int i = 0; i <= n; i ++) {
        cout << suffix[i] << " ";
    }
    cout << endl;
    return 0;
}