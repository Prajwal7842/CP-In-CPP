#include<bits/stdc++.h>
using namespace std;


/*Count Inversions using BIT */
/* Works for Negative Numbers in array */

vector<int> bit;

int query(int i){
	int sum = 0;
	i ++;
	while(i>0){
		sum += bit[i];
		i -= (i&(-i));
	}
	return sum;
}

void update(int i, int delta){
	i ++;
	int size = bit.size()-1;
	while(i<=size){
		bit[i] += delta;
		i += (i&(-i));
	}
}
void convert(vector<int> &arr, int n){
	vector<int> temp(arr.begin(), arr.end());
	sort(temp.begin(), temp.end());
	for(int i = 0; i < n ; i ++){
		arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
	}
}

int getInversionCount(vector<int> &arr){
	int n = arr.size();
	int count = 0;
	convert(arr, n);
	bit.resize(n+1, 0);
	for(int i = n-1; i >= 0; i --){
		count += query(arr[i]-1);
		cout << count << " " << i << endl;
		update(arr[i], 1);
	}
	return count;
}


int main(){
	vector<int> arr = {56,80, 43, 20, 21, 31, 42, 78, 90, 1, 0, -1, -9, -100};
	int n = arr.size();
	cout << getInversionCount(arr) << endl;
}