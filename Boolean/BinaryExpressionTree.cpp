#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 998244353;

struct Node {
    char op;
    Node* left;
    Node* right;
    Node() {
        op = ' ';
        left = NULL;
        right = NULL;
    }
};

int mul(int a, int b) {
    return ((a%mod) * (b%mod)) % mod;
}


class ExpressionTree {
public:
    string exp;
    Node* root;
    ExpressionTree(string& s) {
        exp = s;
    }
    void preprocess() {
        string s = toPostfix(exp);
        root = construct(s);
        process(root);
    }
    Node* newNode(char ch) {
        Node* temp = new Node();
        temp->op = ch;
        return temp;
    }
    int priority(char ch) {
        if(ch == '^') return 1;
        if(ch == '|') return 2;
        if(ch == '&') return 3;
        else return -1;
    }
    bool isOperand(char ch) {
        return ch == '#';
    }
    string toPostfix(string s)
    {   
        string ans = "";
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i ++) {
            if(isOperand(s[i])) {
                ans += s[i];
            }
            else if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                while((!st.empty()) && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty() && st.top() == '(') st.pop();
            }
            else {
                while((!st.empty()) && (priority(s[i]) <= priority(st.top()))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    Node* construct(string s) {
        stack<Node*> st;
        int n = s.size();
        Node *root, *left, *right;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '#') {
                root = newNode(s[i]);
                st.push(root);
            }
            else {
                root = newNode(s[i]);
                left = st.top();
                st.pop();
                right = st.top();
                st.pop();
                root->left = left;
                root->right = right;
                st.push(root);
            }
        }
        root = st.top();
        st.pop();
        return root;
    }
    void process(Node* root) {
        
    }
};

void solve() {
    string s; cin >> s;
    ExpressionTree tree(s);
    tree.preprocess();
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}