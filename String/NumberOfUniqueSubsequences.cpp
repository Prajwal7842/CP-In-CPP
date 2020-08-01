#include<bits/stdc++.h>
using namespace std;
#define int long long int

/* 
    dp[i][j] = Number of Unique Subsequences of length j from characters from s[0 .. i]
    dp[n][i] = Number of Unique Subsequnces of length i
*/

int mod = 1e13;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> last(26, -1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= n; j ++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            } 
            if(i == 0) {
                continue;
            }
            if(i < j)continue;
            int index = s[i-1] - 'a';
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            if(last[index] != -1) {
                dp[i][j] -= dp[last[index]][j-1];
            }
            dp[i][j] = ((dp[i][j]%mod) + mod)%mod;
        }
        if(i > 0) {
            int index = s[i-1] - 'a';
            last[index] = i - 1;
        }
    }
}