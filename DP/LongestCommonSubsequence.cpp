#include<bits/stdc++.h>
using namespace std;

/* Longest Common Subsequence in O(mn) */

int LCS(vector<char> s1, vector<char> s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    vector<char> s1 = {'A', 'G', 'G', 'T', 'A', 'B'};
    vector<char> s2 = {'G', 'X', 'T', 'X', 'A', 'Y', 'B'};
    cout << LCS(s1, s2) << endl;
    return 0;
}