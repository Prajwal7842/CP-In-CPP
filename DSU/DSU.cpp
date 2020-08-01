#include<bits/stdc++.h>
using namespace std;

class DSU
{
public:
	vector<int> arr;
	vector<int> size;
	int n;
	DSU(int nn)
	{
		n = nn;
		arr.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
			size[i] = 1;
		}
	}
	int root(int i)
	{
		while (arr[i] != i)
		{
			arr[i] = arr[arr[i]];
			i = arr[i];
		}
		return i;
	}

	void Union(int i, int j)
	{
		int roota = root(i);
		int rootb = root(j);
		if (roota == rootb)
			return;
		if (size[roota] < size[rootb])
		{
			arr[roota] = arr[rootb];
			size[rootb] += size[roota];
		}
		else
		{
			arr[rootb] = arr[roota];
			size[roota] += size[rootb];
		}
	}
};

int32_t main(){
	int n;
	cin>>n;
	vector<pair<int, int>> input(n,pair<int, int>());
	DSU dsu(n+1);
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		input[i] = make_pair(u,v);
	}
	return 0;
}

