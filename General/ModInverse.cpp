#include<bits/stdc++.h>
using namespace std;
#define int long long 

int power(int x, int y, int p) 
{ 
    int res = 1;
    x = x % p;
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
}   

int modInverse(int n, int p){ 
    return power(n, p-2, p); 
}
 


int32_t main(){
    cout << modInverse(1, 1e9+9);
	return 0;
}
