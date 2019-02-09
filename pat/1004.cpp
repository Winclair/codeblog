#include<iostream>
#include<vector>
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


	vector<int> v{1}, n_left;
	int size = v.size();
	while(size){
		int nl = 0;
		vector<int> temp;
		for(auto i: v){
			if(node[i].size() == 0) nl++;
			else copy(node[i].begin(), node[i].end(), back_inserter(temp)); 
		}
		n_left.push_back(nl);
		size = temp.size();
		v = temp;
	}
	cout << n_left[0];
	int sn = n_left.size();
	for (int i = 1; i < sn; ++i)
	    printf(" %d", n_left[i]);
	printf("\n");

}
