#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Custom set comparator

int32_t main() {
    auto lexical_compare = [](int a, int b) { return to_string(a) < to_string(b); };
    set<int, decltype(lexical_compare)> s(lexical_compare);
 
    s.insert(1);
    s.insert(10);
    s.insert(11);
    s.insert(100);
 
    for (int x : s)
        cout << x << ' ';
 
    return 0;
}
