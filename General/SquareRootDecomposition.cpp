/* Range Sum from l to r online Queries */

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> block;
int sz = 0;

void update(int index, int val) {
    int blkNumber = index/sz;
    block[blkNumber] += val-arr[index];
    arr[index] = val;
}

int query(int l, int r) {
    int ans = 0;
    while(l<r && (l%sz)!=0 && l!=0) {
        ans += arr[l];
        l ++;
    }
    while((l+sz) <= r) {
        ans += block[l/sz];
        l += sz;
    }
    while(l<=r) {
        ans += arr[l];
        l ++;
    }
    return ans;
}

void preprocess() {
    int n = arr.size();
    sz = sqrt(n);
    block.assign(sz+1, 0); 
    int sum = 0;
    int index = -1;
    for(int i = 0; i < n; i ++) {
        if((i%sz) == 0) {
            index ++;
        }
        block[index] += arr[i];
    }
}

int main(){
    arr = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    preprocess();
    for(auto i:block) cout << i << endl;
    cout << "query(3,8) : " << query(3, 8) << endl; 
    cout << "query(1,6) : " << query(1, 6) << endl; 
    update(8, 0); 
    cout << "query(8,8) : " << query(8, 8) << endl; 
    return 0;
}