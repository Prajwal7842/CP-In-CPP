#include<bits/stdc++.h>
using namespace std;
#define print(arr,n)for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl
/*Should be 1 based indexing*/

int n;
vector<int> arr;
vector<int> segtree;
vector<int> lazy;
vector<bool> islazy;

void combine(int &res, int &a, int &b){
	res = min(a,b);
}

void build(int curr, int left, int right){
	if(left == right){
		segtree[curr] = arr[left];
		return;
	}
	int mid = (right+left)/2;
	build(curr*2, left, mid);
	build(curr*2+1, mid+1, right);
	combine(segtree[curr], segtree[curr*2], segtree[curr*2+1]);
}

void lazyUpdate(int curr, int l, int r){
	if(l!=r){
		islazy[curr<<1] = 1;
		islazy[curr<<1|1] = 1;
		lazy[curr*2] = lazy[curr];
		lazy[curr*2+1] = lazy[curr];
	}
	segtree[curr] = lazy[curr];
	islazy[curr] = 0;
}

void RangeUpdate(int curr, int l, int r, int i, int j, int val){
	if(islazy[curr]){
		lazyUpdate(curr, l, r);
	}
	if(j<l || i>r || i>j){
		return;
	}
	if(i<=l && r<=j){
		islazy[curr]=1;
		lazy[curr] = val;
		lazyUpdate(curr, l, r);
		return;
	}
	int mid = (l+r)/2;
	RangeUpdate(curr*2, l, mid, i, j, val);
	RangeUpdate(curr*2+1, mid+1, r, i, j, val);
	combine(segtree[curr], segtree[curr*2], segtree[curr*2+1]);
}
void PointUpdate(int curr, int l, int r, int pos, int val){
	if(islazy[curr]){
		lazyUpdate(curr, l, r);
	}
	if(l==r){
		islazy[curr] = 1;
		lazy[curr] = val;
		lazyUpdate(curr, l, r);
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid){
		PointUpdate(curr*2, l, mid, pos, val);
	}
	else{
		PointUpdate(curr*2+1, mid+1, r, pos, val);
	}
	combine(segtree[curr], segtree[curr*2], segtree[curr*2+1]);
}

int RangeQuery(int curr, int l, int r, int i, int j){
	if(islazy[curr])
		lazyUpdate(curr, l, r);
	if(j<l || i>r)
		return 1e9;
	if(i<=l && r<=j){
		return segtree[curr];
	}
	int mid = (l+r)/2;
	int left = RangeQuery(curr*2, l, mid, i, j);
	int right = RangeQuery(curr*2+1, mid+1, r, i, j);
	int val = 1e9;
	combine(val, left, right);
	return val;
}

int PointQuery(int curr, int l, int r, int pos){
	if(islazy[curr]){
		lazyUpdate(curr, l, r);
	}
	if(l==r){
		return segtree[curr];
	}
	int mid = (l+r)/2;
	if(pos<=mid){
		return PointQuery(curr*2, l, mid, pos);
	}
	else{
		return PointQuery(curr*2+1, mid+1, r, pos);
	}
}

int query(int pos){
	return PointQuery(1,1,n,pos);
}

int query(int l, int r){
	return RangeQuery(1,1,n,l,r);
}

void update(int l, int r, int val){
	RangeUpdate(1,1,n,l,r,val);
}

void update(int pos, int val){
	PointUpdate(1,1,n,pos,val);
}


int32_t main(){
	
	cin>>n;
	arr.assign(n+1,0);
	segtree.assign(4*n+1,0);
	lazy.assign(4*n+1,0);
	islazy.assign(4*n+1,0);

	for(int i=1;i<=n;i++)cin>>arr[i];
	build(1,1,n);

	while(true){
		int pos;
		cin>>pos;
	}
	print(segtree, 3*n);
	return 0;
}
