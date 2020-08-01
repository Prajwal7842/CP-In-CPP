#include<bits/stdc++.h>
using namespace std;


void Z_Function(vector<int> &z, string s){
	int n = s.size();
	int l = 0, r = 0;
	for(int i = 1; i < n; i ++){
		if(i <= r){
			z[i] = min(r - i + 1, z[i - l]);
		}
		while((i + z[i] < n) && (s[z[i]] == s[i+z[i]])){
			++z[i];
		}
		if((i + z[i] - 1) > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void Z_Algorithm(string text, string pattern){
	string s = pattern + "$" + text;
	vector<int> z(s.size(), 0);
	cout << s << endl;
	Z_Function(z, s);
	for(auto i:z){
		cout << i << " ";
	}
	for(int i = 1; i < s.size(); i ++){
		if(z[i] == pattern.size())
			cout << (i - pattern.size() - 1) << endl;
	}
}


int main(){
	string text = "AAABCDAACDAA";
	vector<int> z(text.size(), 0);
	Z_Function(z, text);
	for(auto i:z){
		cout << i << " ";
	}
	cout << endl;
	Z_Algorithm("AAABCDAACDAA", "AA");
	return 0;
}



// Application 1 : Number of Substrings that occurs i times of string s. 

//Tested
/* count[i] = Number of Substrings of String s occuring atleast i times. */
// O(n^2)

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> count(n+2, 0);
    for(int i = 0; i < n; i ++) {
        string st = s.substr(i);
        vector<int> z = Z_Function(st);
        int l = st.size();
        vector<int> cnt(l + 1, 0);
        for(int ii = 0; ii < l; ii ++) {
            int val = z[ii];
            cnt[0] += 1;
            cnt[val + 1] -= 1;
        }
        for(int ii = 1; ii < l; ii ++) cnt[ii] += cnt[ii-1];
        for(int ii = 1; ii < l; ii ++) {
            count[cnt[ii] + 1] ++;
        }
    }
    count[1] = (n*(n+1))/2;
    for(int i = 2; i <= n; i ++) {
        count[1] -= count[i];
    }
}