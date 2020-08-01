#include<bits/stdc++.h>
using namespace std;
#define int long long int


// Assumption -> p is prime

int power(int x, int y, int mod){
	if(y==0)return 1;
	if(y==1)return x;
	int p = power(x,y/2,mod);
	if((y&1)==0)
		return ((p%mod)*(p%mod))%mod;
	else
		return ((x%mod)*(p%mod)*(p%mod))%mod;
}

int getPrimitive(int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= power (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
