#include<bits/stdc++.h>
using namespace std;
/* lis[i] indicates the longest subsequence terminating at ith index in the array */


 /* LIS in O(n^2) time. */
 vector<int> LIS(vector<int>& arr, int n){
     vector<int> lis(n+1, 1);
     for(int i = 0; i < n; i ++){
         for(int j = i-1; j >= 0 ; j --){
             if(arr[i]>=arr[j] && lis[i] < lis[j]+1){
                 lis[i] = lis[j]+1;
             }
         }
     }
     return lis;
 }

 /* LIS in O(nlogn) time. */

int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
int LIS2(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
    std::vector<int> tail(v.size(), 0); 
    int length = 1; 
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 



int main(){
    // vector<int> arr = {1,5,2,3,2,3,10,2,2,4,1,7};
    // vector<int> lis = LIS(arr, arr.size());
    // cout << lis << endl;
    // cout << (*(max_element(lis.begin(), lis.end()))) << endl;
    // cout << LIS2(arr) << endl;

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    cout << LIS2(arr) << endl;
    return 0;
}
