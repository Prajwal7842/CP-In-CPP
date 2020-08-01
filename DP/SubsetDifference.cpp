#include<bits/stdc++.h>
using namespace std;

/*  Given a set. Partition it into two sets such that abs(sum1-sum2) is minimum 
    Complexity = O(n*sum)
*/


int SubsetDifference(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(sum, 0));
    for(int i = 0; i <= n; i ++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= sum; j ++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
            }
        }
    }
    int diff = sum;
    for(int j = sum/2; j >= 0; j --) {
        if(dp[n][j]) {
            diff = sum-(2*j);
            break;
        }
    }    
    return diff;
}

int main(){
    vector<int> arr = {3, 1, 4, 2, 2, 1};
    cout << SubsetDifference(arr) << endl;
    return 0;
}