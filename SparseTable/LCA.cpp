#include<bits/stdc++.h>
using namespace std;


unordered_map<int, std::vector<int>> g;

unordered_map<int, int> level;

std::vector<std::vector<int>> table(1e6+1, std::vector<int>(50,-1));

/* table[i][j] represents parent of ith node jumping 1<<j times above the tree*/

void bfs(int n, int src){
	queue<int> pq;	
	pq.push(src);
	level[src] = 1;
	while(!pq.empty()){
		int u = pq.front();
		pq.pop();
		for(auto v : g[u]){
			if(level.find(v)==level.end()){
				level[v] = level[u] + 1;
				table[v][0] = u;
				pq.push(v);
			}
		}
	}
}

void fillTable(int n){
	int d = ceil(log2(n));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			int mid = table[i][j-1];
			if(mid!=-1){
				table[i][j] = table[mid][j-1]; 
			}
		}
	}
}

int lca(int i, int j, int n){
	if(level[i]<level[j]){
		int temp = i;
		i = j;
		j = temp;
	}
	int d = ceil(log2(n));
	for(int log=d;log>=0;log--){
		if((level[i] - (1<<log))>=level[j])
			i = table[i][log];
	}
	if(i==j){
		return i;
	}
	for(int log=d;log>=0;log--){
		if(table[i][log] != table[j][log]){
			i = table[i][log];
			j = table[j][log];
		}
	}
	return table[i][0];
}


int main(){

	int n;
	cin>>n;

	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	/* Needed to be run */
	bfs(n,1);
	fillTable(n);
	


	for(int i=1;i<=n;i++,cout<<endl){
		for(int j=0;j<=5;j++){
			cout<<table[i][j]<<" ";
		}
	}

	for(int i=1;i<=n;i++,cout<<endl){
		for(int j=1;j<=n;j++){
			cout<<"LCA of"<<i<<" "<<j<<" : "<<lca(i,j,n)<<endl;
		}
	}

}
