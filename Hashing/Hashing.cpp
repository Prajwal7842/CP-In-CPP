#include<bits/stdc++.h>
using namespace std;
#define int long long int

/* Prefix Hash Function */
/* For Rolling Hash. Use Proper Mods to avoid TLE. Change check function accordingly */

class Hashing {
public:
    string s;
    vector<int> power;
    vector<int> hash;
    int n, mod1, mod2;
    Hashing(string& st, int m1, int m2) {
        s = st;
        n = s.size();
        mod1 = m1;
        mod2 = m2;
        power.resize(2*n+10);
        hash.assign(n+1, 0);
        preprocess();
    }
    int mul(int& a, int& b) {
        int res = a * b;
        if(res > mod2) {
            return res % mod2;
        }
        return res;
    }
    int add(int a, int b)
    {
        int res = a + b;
        if (res > mod2)
        {
            return res % mod2;
        }
        return res;
    }

    int sub(int a, int b)
    {
        int res = a - b;
        if (res < 0)
        {
            res += mod2;
        }
        return res;
    }
    void preprocess() {
        power[0] = 1;
        for(int i = 1; i < 2*n + 10; i ++) {
            power[i] = mul(power[i-1], mod1);
        }
    }
    void computeHash()
    {
        hash[0] = (s[0] - 'a') + 1;
        int e = 1;
        for (int i = 1; i < n; i++)
        {
            int val = (s[i] - 'a') + 1;
            hash[i] = add(hash[i - 1], mul(val, (power[e])));
            e++;
        }
    }
    int get(const int &i, const int &j)
    {
        if (i == 0)
        {
            return hash[j];
        }
        return sub(hash[j], hash[i - 1]);
    };
    bool check(int i, int j)
    {
        
    }
};