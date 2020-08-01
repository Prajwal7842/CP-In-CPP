#include<bits/stdc++.h>
using namespace std;

/*  1 Based Indexing is used in this implementation */

struct Node{
public:
    int num;
    Node():num(0){}
    Node(int n){
        num = num;
    }
};

class BITSum {
public:
    vector<Node> bit;
    int n;
    BITSum(int n) {
        this->n = n;
        bit.resize(n+1);
        for(auto i:bit) i = Node(0);
    }   
    BITSum(vector<Node>& arr) {
        BITSum(arr.size());
        create(arr);
        n = arr.size();
    }
    void create(vector<Node>& arr) {
        for(int i = 0; i < n; i ++) {
            update(arr[i], i);
        }
    }
    void update(Node& delta, int index) {
        while(index<=n) {
            bit[index].num += delta.num;
            index += (index&-index);
        }
    }
    void update(Node delta, int l, int r) {
        update(delta, l);
        delta.num = -delta.num;
        update(delta, r+1);
    }
    int sum(int index) {
        int res = 0;
        while(index>0) {
            res += bit[index].num;
            index -= (index&-index);
        }
        return res;
    }
    int sum(int l, int r) {
        return sum(r)-sum(l-1);
    }
    int read(int index) {
        return sum(index)-sum(index-1);
    }
    void scale(int c) {
        for(int i = 1; i <= n; i ++) {
            bit[i].num/=c;
        }
    }
};

int main(){
    return 0;
}