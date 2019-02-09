#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;

struct child{
	int left, right;	
};

void in_order(vector<child> &node, int root, vector<int> &want){
	if(root == -1) return ;
	in_order(node, node[root].left, want);
	want.push_back(root);
	in_order(node, node[root].right, want);
}


void lever_order(vector<child> &node, int root, vector<int> &want){
	vector<int> v = {root};
	int size = 1;
	while(size){
		vector<int> temp;
		for(auto i: v){
			if(i == -1) continue;
			want.push_back(i);
			temp.push_back(node[i].left); 
			temp.push_back(node[i].right); 
		}
		size = temp.size();
		v = temp;
	}
}

void print(vector<int> v){
	cout << v[0];
	int sn = v.size();
	for (int i = 1; i < sn; ++i)
		printf(" %d", v[i]);
	printf("\n");	
}

int main() {
	int n; cin >> n;
	vector<child> node(n);
	vector<int> is_root(n, 1);
	for (int i = 0; i < n; ++i){
		char l, r; cin >> l >> r;
		if(l == '-') node[i].right = -1;
		else {
			is_root[l - '0'] = 0;
			node[i].right = l - '0';
		}
		if(r == '-') node[i].left = -1;
		else {
			is_root[r - '0'] = 0;
			node[i].left = r - '0';
		} 
	}
	int root;
	for (int i = 0; i < n; ++i)
		if(is_root[i]) root = i;

	vector<int> lever, in;
	lever_order(node, root, lever);	
	in_order(node, root, in);
	print(lever);
	print(in);

}
