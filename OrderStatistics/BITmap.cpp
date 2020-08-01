#include <bits/stdc++.h>
using namespace std;
#define int long long int

// To handle negative elements add a constant to the index
// Order Statistics using bit and std::map

class BIT
{
public:
    map<int, int> bit;
    int limit = 1e10;
    void update(int idx, int val = 1)
    {
        while (idx < limit)
        {
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }
    int sum(int idx)
    {
        int ans = 0;
        while (idx > 0)
        {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
    int KthSmallest(int k) {
        int l = 0, r = limit;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(k <= sum(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    int rank(int val)
    {
        return sum(val);
    }
};

int32_t main() {
    return 0;
}