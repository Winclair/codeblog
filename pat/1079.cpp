#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;

struct Attr{
	vector<int> childs;
	int amount;
};

int main() {
	int n; cin >> n;
	double price, rate; cin >> price >> rate;
	vector<Attr> node(n);
	
	for (int i = 0; i < n; ++i){
		int k; cin >> k;
		if(k == 0) {cin >> node[i].amount; continue;}
		vector<int> &cd = node[i].childs;
		for (int j = 0; j < k; ++j){
			int c; cin >> c;
			cd.push_back(c);
		}		 				 			
	}

	vector<int> v{0};
	int level = 0, size = 1;
	double total = 0;

	while(size){
		level++; 
		vector<int> temp;
		for(auto i: v){
			vector<int> &cd = node[i].childs;
			if(cd.size() == 0)
				total += price*pow(1+rate/100, level-1)*(node[i].amount);
			else copy(cd.begin(), cd.end(), back_inserter(temp)); 
		}
		size = temp.size();
		v = temp;
	}

	printf("%.1f\n", total);

}
