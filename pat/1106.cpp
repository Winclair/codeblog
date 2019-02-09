#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	double price, rate; cin >> price >> rate;
	vector<vector<int>> node(n);
	
	for (int i = 0; i < n; ++i){
		int k; cin >> k;
		for (int j = 0; j < k; ++j){
			int c; cin >> c;
			node[i].push_back(c);
		}		 				 			
	}

	vector<int> v = node[0];
	int level = 1, reter = 1;
	int size = v.size();
	while(size){
		reter = 0;
		level++; 
		vector<int> temp;
		for(auto i: v){
			if(node[i].size() == 0) reter++;
			else copy(node[i].begin(), node[i].end(), back_inserter(temp)); 
		}
		if(reter) break;
		size = temp.size();
		v = temp;
	}

	printf("%.4f %d\n", price*pow(1+rate/100, level-1), reter);

}
