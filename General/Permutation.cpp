//Tested
#include<bits/stdc++.h>
using namespace std;
// #include"Template.cpp"

/* Cycle Decomposition in Permutation from 1 to n */
/* Strictly use indexes */

class Permutation {
public:
    vector<int> arr;
    int n;
    Permutation(int size) {
        n = size;
        arr.assign(n, 0);
    }
    void reverse(int l, int r) {
        std::reverse(arr.begin() + l, arr.begin() + r + 1);
    }
    int decompose() {
        vector<bool> visited(n, 0);
        function<void (int)> dfs = [&](int src) {
            visited[src] = 1;
            if(visited[arr[src]]) return;
            dfs(arr[src]);
        };
        int cycleCount = 0;
        for(int i = 0; i < n; i ++) {
            if(!visited[i]) {
                dfs(i);
                cycleCount += 1;
            }
        }
        return cycleCount;
    }
    int getParity() {
        int cycleCount = decompose();
        int parity = (n-cycleCount);
        return (parity&1);
    }
};

int32_t main() {
    int n;
    cin >> n;
    Permutation perm(n);
    for(int i = 0; i < n; i ++) {
        int x; cin >> x; x --;
        perm.arr[i] = x;
    }
}