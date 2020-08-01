#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = (1e9) + 7;

int limit = 5005;
const int mod = (1e9) + 7;

vector<vector<int>> nCr(limit, vector<int>(limit, 0));

void preprocess() {
    for(int i = 0; i < limit; i ++) {
        for(int j = 0; j < limit; j ++) {
            if(j == 0) {
                nCr[i][j] = 1;
                continue;
            }
            if(j > i) {
                break;
            }
            nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            if(nCr[i][j] > mod) {
                nCr[i][j] %= mod;
            }
        }
    }
}

int32_t main() {
    preprocess();
    return 0;
}