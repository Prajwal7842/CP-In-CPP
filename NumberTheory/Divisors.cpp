#include<bits/stdc++.h>
using namespace std;


vector<int> PrimeDivisors(int n){
	vector<int> divisors;
	if((n&1) == 0){
		divisors.push_back(2);
		while((n&1) == 0){
			n >>= 1;
		}
	}
	for(int i = 3; i*i <= n; i += 2){
		if((n%i) == 0){
			divisors.push_back(i);
			while((n%i) == 0){
				n /= i;
			}
		}
	}
	if(n>2){
		divisors.push_back(n);
	}
	return divisors;
}

// All Divisors
vector<int> Divisors(int n) 
{ 
    vector<int> v; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i)
            	v.push_back(i); 
            else
            { 
            	v.push_back(i);
                v.push_back(n/i); 
            } 
        } 
    } 
    sort(v.begin(), v.end());
    return v;
}

/*Returns Count of Total Number of Divisors 
	N = (a1^p1)*(a2^p2)..
	Count = (p1+1)*(p2+1)..
*/
int countDivisors(int n){
	vector<int> divCount(1e5+1,0);
	int count = 1;
	for(int i = 2; i*i <= n; i ++){
		if(n%i == 0){
			int c = 0;
			while(n%i == 0){
				c ++;
				n/=i;
			}
			count *= (c+1);
		}
	}
	if(n>1){
		count *= 2;
	}
	return count;
}

int main(){
	return 0;
}