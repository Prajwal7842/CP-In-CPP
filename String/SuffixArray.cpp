//Tested
#include<bits/stdc++.h>
using namespace std;

// Build SuffixArray In O(n log(n)) time

void RadixSort(vector<pair<pair<int, int>, int>>& arr) {
    int n = arr.size();
    vector<vector<pair<int, int>>> cnt(n);
    for(auto i : arr) {
        cnt[i.first.second].push_back({i.first.first, i.second});
    }
    int index = 0;
    for(int i = 0; i < n; i ++) {
        for(auto j : cnt[i]) {
            arr[index] = {{j.first, i}, j.second};
            index ++;
        }
    }
    for(auto &i : cnt) {
        i.clear();
    }
    for(auto i : arr) {
        cnt[i.first.first].push_back({i.first.second, i.second});
    }
    index = 0;
    for(int i = 0; i < n; i ++) {
        for(auto j : cnt[i]) {
            arr[index] = {{i, j.first}, j.second};
            index ++;
        }
    }
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
        vector<pair<pair<int, int>, int>> arr(n);
        for(int i = 0; i < n; i ++) {
            arr[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        RadixSort(arr);
        for(int i = 0; i < n; i ++) suffix[i] = arr[i].second;
        c[suffix[0]] = 0;
        for(int i = 1; i < n; i ++) {
            if((arr[i].first.first == arr[i-1].first.first) && (arr[i].first.second == arr[i-1].first.second)) {
                c[suffix[i]] = c[suffix[i-1]];
            }
            else {
                c[suffix[i]] = c[suffix[i-1]] + 1;
            }
        }
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