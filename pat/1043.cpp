#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;

void post_order(vector<int> &pre, vector<int> &want, bool &is, bool rbl){
	int size = pre.size();
	if(size == 0) return ;
	if(size == 1){ want.push_back(pre[0]); return ;}
	vector<int> left, right;
	
	int i = 1;
	while( (i<size) && !((pre[i] >= pre[0]) ^ rbl)){
		left.push_back(pre[i]);
		i++;
	}
	while(i<size){
		if(!((pre[i] >= pre[0]) ^ rbl)){ is = false; return ; }
		right.push_back(pre[i]);
		i++;
	}
	post_order(left, want, is, rbl);
	post_order(right, want, is, rbl);
	want.push_back(pre[0]);
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
	vector<int> pre(n), want;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	bool is = true;
	bool rbl = (pre.size() > 1)? (pre[1]>=pre[0]): true;
	post_order(pre, want, is, rbl);
	if(is){
		cout << "YES\n";
		print(want);
	}else cout << "NO\n";
}
