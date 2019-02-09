#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int main() {
	int n, m, s; cin >> n >> m >> s;
	vector<vector<int>> path;
	vector<int> weight(n), parent(n);
	vector<int> node(n);
	parent[0] = -1;
	for (int i = 0; i < n; ++i) cin >> weight[i];
	for (int i = 0; i < m; ++i){
		int p, k; cin >> p >> k;
		node[p] = 1;
		for (int j = 0; j < k; ++j){
			int c; cin >> c;
			parent[c] = p;
		}		 				 			
	}


	for (int i = 0; i < n; ++i){
		if(node[i]) continue; 
		vector<int> v;
		int p = i, summ = 0;
		while(p != -1){
			summ += weight[p];
			v.insert(v.begin(), weight[p]);
			p = parent[p];
		}
		if(summ == s) path.push_back(v);
	}

	sort(path.begin(), path.end());

	for (auto it = path.rbegin(); it != path.rend(); ++it){
		vector<int> &v = *it;  
		cout << v[0];
		int sn = v.size();
		for (int i = 1; i < sn; ++i)
		    printf(" %d", v[i]);
		printf("\n");	
	}
	
}
