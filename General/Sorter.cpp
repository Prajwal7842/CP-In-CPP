#include<bits/stdc++.h>
using namespace std;

/*Sort in Descending Order By first Element */
bool compare(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first != p2.first)
      return p1.first > p2.first;
    return p1.second > p2.second;
}

int main(){
    int n = 10;
    vector<pair<int, int>> arr;
    for(int i = 0 ; i < n ; i ++)
        arr.push_back({rand(), rand()});
    sort(arr.begin(), arr.end(), compare);
    for(auto i:arr)
      cout << i.first << " " << i.second << endl;
    return 0;
}
