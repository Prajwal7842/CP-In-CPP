#include<bits/stdc++.h>
using namespace std;

/* Change Combine Function */
/*Works for : 
-> Minimum
-> Maximum
-> GCD
*/

class SparseTable {
public:
	int MAXN;
	int sz;
	vector<vector<int>> table;
	SparseTable() {

	}
	int combine(int &a, int &b)
	{
		return min(a, b);
	}
	void preprocess(const vector<int> &arr, int N, int k = 25)
	{
		MAXN = N;
		sz = k;
		int n = arr.size();
		table.assign(MAXN, vector<int>(sz, 0));
		for (int i = 0; i < n; i++)
		{
			table[i][0] = arr[i];
		}
		for (int j = 1; j <= sz; j++)
		{
			for (int i = 0; (i + (1 << j)) <= n; i++)
			{
				table[i][j] = combine(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int l, int r)
	{
		/* Uses 0 based indexing */
		int index = (int)(log2(r - l + 1));
		return combine(table[l][index], table[r - (1 << index) + 1][index]);
	}
	void printTable()
	{
		for (int i = 0; i < MAXN; i++, cout << endl)
		{
			for (int j = 0; j < sz; j++)
			{
				cout << table[i][j] << " ";
			}
		}
	}
};


int main(){
	vector<int> arr = { 7, 21, 3, 10, 5, 10, 3, 12, 18 };
	int n = arr.size();
	SparseTable table;
	table.preprocess(arr,n);  
	cout<<table.query(2,4)<<endl;
	cout<<table.query(0, 1)<<endl;
	cout<<table.query(0,n-1)<<endl;
	return 0;
}
