#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;



int main() {
	int n; cin >> n;
	double price, rate; cin >> price >> rate;
	vector<vector<int>> node(n);
	int root;
	for (int i = 0; i < n; ++i){
		int p; cin >> p;
		if(p == -1) {root = i; continue;}
		node[p].push_back(i);	 			
	}

	vector<int> v = node[root], last = {root};
	int level = 1;
	int size = v.size();
	while(size){
		level++; 
		vector<int> temp;
		for(auto i: v)
			copy(node[i].begin(), node[i].end(), back_inserter(temp)); 
		size = temp.size();
		last = v;
		v = temp;
	}

	printf("%.2f %d\n", price*pow(1+rate/100, level-1), last.size());

}
