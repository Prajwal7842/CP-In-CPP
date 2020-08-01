#include<bits/stdc++.h>
using namespace std;

/*  Edit Distance in O(mn)
    Operations : Insert, Replace, Delete 

    Fact : If one string is empty remove all characters of other string.
*/



int Min(int a, int b, int c) {
    return min(a, min(b, c));
}

int editDistance(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            if(i == 0)
                dp[i][j] = j; 
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + Min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    string s1 = "sunday";
    string s2 = "saturday";
    cout << editDistance(s1, s2) << endl;
    return 0;
}