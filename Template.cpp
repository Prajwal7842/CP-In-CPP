// -D_GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl
#define rep(a,b,in) for(int i=a;i<b;i+=in)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
using namespace std;


#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)

template<typename T, typename U>
ostream& operator <<(ostream& os, pair<T, U>& p){
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, set<T>& s){
	for(auto i:s){
		os << i << " ";
	}
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, set<T, greater<T>>& s){
	for(auto i:s){
		os << i << " ";
	}
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, unordered_set<T>& s){
	for(auto i:s){
		os << i << " ";
	}
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, multiset<T>& s){
	for(auto i:s){
		os << i << " ";
	}
	return os;
}


template<typename T>
ostream& operator <<(ostream& os, multiset<T, greater<T>>& s){
	for(auto i:s){
		os << i << " ";
	}
	return os;
}

template<typename T, typename U>
ostream& operator <<(ostream& os, map<T, U>& mp){
	for(auto i:mp){
		os << i.first << " -> " << i.second << endl;
	}
	return os;
} 

template<typename T,  typename U>
ostream& operator <<(ostream& os, unordered_map<T, U>& mp){
	for(auto i:mp){
		os << i.first << " -> " << i.second << endl;
	}
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, vector<T>& vec){
	os << "[";
	int l = vec.size();
	for(int i = 0; i < l-1; i ++){
		os << vec[i] << ", ";
	}
	os << vec[vec.size()-1] << "]";
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, vector<vector<T>>& vec){
	for(auto i:vec) {
		for(auto j:i) {
			os << j << " ";
		} 
		os << endl;
	}
	return os;
}

// int getRandInt() {
// 	return (int)((int)(rand())%((int)(1e3)));
// }




