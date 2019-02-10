#include<iostream>
#include<string>
#include<vector>
#include <cstdio>

using namespace std;


struct Node{
	int left, right;
};

void maxix(vector<Node> &ids, int root, int index, int &maxn, int &last) {
    if(index > maxn) {
        maxn = index;
        last = root;
    }
    if(ids[root].left != -1) maxix(ids, ids[root].left, index * 2 , maxn, last);
    if(ids[root].right != -1) maxix(ids, ids[root].right, index * 2 + 1, maxn, last);
}

int main() {
	int n; cin >> n;
	vector<Node> ids(n);
	vector<int> is_root(n, 1);
	for (int i = 0; i < n; ++i){
		string l, r; cin >> l >> r;
		if(l == "-") ids[i].left = -1;
		else {
			is_root[stoi(l)] = 0;
			ids[i].left = stoi(l);
		}
		if(r == "-") ids[i].right = -1;
		else {
			is_root[stoi(r)] = 0;
			ids[i].right = stoi(r);
		} 
	}

	int root;
	for (int i = 0; i < n; ++i)
		if(is_root[i]) {root = i; break;}
	
	int maxn = -1, last = 0;
	maxix(ids, root, 1, maxn, last);
    if (maxn == n) cout << "YES " << last;
    else cout << "NO " << root;
}
