#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = (1e9) + 7;

// solve(n, k) => No. of ways to partition a set of n elements into k subsets

// m -> number of elements atleast in one set

vector<vector<int>> dp;

int solve(int nn, int cc, int m = 1) {
    dp.assign(nn+1, vector<int>(cc+1, 0));
    if(m == 1){
        dp[0][0] = 1;
        for(int n = 1; n <= nn; n ++) {
            for(int c = 1; c <= cc; c ++){
                dp[n][c] = c*dp[n-1][c] + dp[n-1][c-1];
                dp[n][c] %= mod;
            }
        }
        return dp[nn][cc];
    }
    else if(m == 2){
        dp[0][0] = 1;
        for(int n = 2; n <= nn; n ++) {
            for(int c = 1; c <= cc; c ++){
                dp[n][c] = c*dp[n-1][c] + (n-1)*dp[n-2][c-1];
                dp[n][c] %= mod;
            }
        }
        return dp[nn][cc];
    }
    dp[0][0] = 1;
    for(int n = 3; n <= nn; n ++) {
        for(int c = 1; c <= cc; c ++){
            dp[n][c] = c*dp[n-1][c] + (((n-1)*(n-2))/2)*dp[n-3][c-1];
            dp[n][c] %= mod;
        }
    }
    return dp[nn][cc];
}


int32_t main() {
    int t;
    cin >> t;
    while(t --) {
        int n, c, m; cin >> n >> c >> m;
        cout << solve(n, c) << endl;
    }
}