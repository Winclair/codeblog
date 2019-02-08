#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> node(n+1);
	for (int i = 0; i < m; ++i){
		int p, k; cin >> p >> k;
		for (int j = 0; j < k; ++j){
			int c; cin >> c;
			node[p].push_back(c);
		} 			
	}
	
	vector<int> v = node[1];
	int size = v.size();
	int num = 1, level = 1, wantl = 1;
	while(size){
		level++; 
		if(size > num){
			num = size; wantl = level; 
		}
		vector<int> temp;
		for(auto i: v)
			copy(node[i].begin(), node[i].end(), back_inserter(temp));
		size = temp.size();
		v = temp; 
	}
	printf("%d %d\n", num, wantl);

}

