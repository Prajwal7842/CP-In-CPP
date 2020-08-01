#include<bits/stdc++.h>
using namespace std;
// #include"Template.cpp"


// LPS -> Longest Palindromic Subsequence
/* lps[i] = Radius of the largest palindrome centered at index i / 2. */

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
}
 
template <typename T>
vector<int> LPS(const T &s) {
  return manacher((int) s.size(), s);
}

bool is_palindrome(vector<int>& lps, int l, int r, int n) {
	return l>=0 && r<n && (2*lps[r+l]) >= r-l;
}

int main(){
    string s;
    cin >> s;
    vector<int> lps = LPS(s);
    return 0;
}