#include<bits/stdc++.h>
using namespace std;
#define print(arr,n)for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl


// Returns the prime factors with their frequency.
void getPrimeFactors(vector<map<int, int>>& prime, int limit) {
	int nn = limit;
	for(int i = 2; i < nn; i ++) {
		int n = i;
		if((n&1) == 0){
			while((n&1) == 0){
				n >>= 1;
				prime[i][2] ++;
			}
		}
		for(int j = 3; j*j <= n; j += 2){
			if((n%j) == 0){
				while((n%j) == 0){
					n /= j;
					prime[i][j] ++;
				}
			}
		}
		if(n>2){
			prime[i][n] ++;
		}
	}
}



void calPrimeFactors(int n, std::vector<int> arr, std::vector<int>& factors){
	while(n!=1){
		cout<<arr[n]<<endl;
		factors.push_back(arr[n]);
		while(n>1 && (n%arr[n]) == 0){
			n/=arr[n];
		}
	}
}



void LinearSeive(std::vector<int> &arr, std::vector<int>& primes, int n){
	for(int i=2;i<n;i++){
		if(arr[i]==0){
			arr[i]=i;
			primes.push_back(i);
		}
		int j=0;
		while(j<(int)(primes.size()) && primes[j]<=arr[i] && (i*primes[j])<n){
			arr[i*primes[j]]=primes[j];
			j++;
		}
	}
}

int main(){
	std::vector<int> arr(1e3,0);
	std::vector<int> primes;
	int n = 1e3+1;
	LinearSeive(arr,primes,n);
	print(arr,100);
	int no = 1e4+3;
	std::vector<int> factors;
	calPrimeFactors(no,arr,factors);
	for(auto i:factors)cout<<i<<" ";cout<<endl;
	return 0;
}