#include<bits/stdc++.h>
using ll = long long int;
#define int ll
using namespace std;

int power(int x, int y, int mod){
	if(y==0)return 1;
	if(y==1)return x;
	int p = power(x,y/2,mod);
	if((y&1)==0)
		return ((p%mod)*(p%mod))%mod;
	else
		return ((x%mod)*(p%mod)*(p%mod))%mod;
}


int power(int x, int y){
	if(y==0)return 1;
	if(y==1)return x;
	int p = power(x,y/2);
	if((y&1)==0)
		return (p*p);
	else
		return (x*p*p);
}


int32_t main(){
	int mod = 1e7+9;
	int x,y;
	cin>>x>>y;
	cout<<power(x,y,mod)<<endl;
	return 0;
}

