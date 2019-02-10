#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>

using namespace std;

int log2(int n){
	int i = 0;
	while(n = (n >> 1)) i++;
	return i;
}

int n_left(int m){
	int level = log2(m+1);
	int fn = pow(2, level - 1) - 1;
	int leaf = m - 2*fn - 1;
	return ((leaf > fn+1)? 2*fn+1: fn+leaf); 
}


void level_order(const vector<int> &v, map<int, int> &want, int index){
	int size = v.size();
	if(size == 0) return;
	int nl = n_left(size);
	want.insert({index, v[nl]});	
	auto b = v.begin(), e = v.end();   
	level_order(vector<int>(b, b + nl), want, 2*index + 1);
	level_order(vector<int>(b + nl + 1, e), want, 2*index + 2);
}


int main() {
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> want;
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	level_order(v, want, 0);

	cout << want[0];
	for(auto i: want)
		if(i.first == 0) continue; 
		else cout << " " << i.second;	
}
