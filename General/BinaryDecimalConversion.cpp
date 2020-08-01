#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> convertToBinary(int n){
	vector<int> arr(64, 0);
	int bitIndex = 63;
	while(n>0){
		arr[bitIndex] = n&1;
		n >>= 1;
		bitIndex --;
	}
	return arr;
}

int convertToDecimal(vector<int>& arr){
	int decimalNumber = 0;
	int power = 1;
	int l = arr.size();
	for(int i=l-1;i>=0;i--){
		decimalNumber += (arr[i]*power);
		power <<= 1;
	}
	return decimalNumber;
}

int main(){
	return 0;
}
