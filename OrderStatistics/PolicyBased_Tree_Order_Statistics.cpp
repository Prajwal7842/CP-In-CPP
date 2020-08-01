#include<bits/stdc++.h>
using namespace std;

//Don't use #define int long long int with these

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define T int //Define Type here

//To use a map, replace null_type with data type
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

//find_by_order(k) returns an iterator to k-th largest element(starting from 0)
//order_of_key(k) returns the number of items in set strictly less than k.
//Duplicates Not allowed

int main(){
	ordered_set s;
	for(int i = 1; i <= 10; i ++){
		s.insert(i);
	}
	cout << *s.find_by_order(2) << endl;
	cout << *s.lower_bound(0) << endl;
	if(s.find_by_order(100) == end(s)){
		cout << "Out of range" << endl;
	}
	cout << s.order_of_key(5) << endl;
	for(auto i:s){
		cout << i << endl;
	}
}


