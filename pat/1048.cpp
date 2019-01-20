#include<iostream>
#include<map>
#include <cstdio>
using namespace std;


int main(){
	int k, n;
	cin>>k>>n;
	map<int, int> mapp;
	for (int i = 0; i < k; ++i){
		int j; cin>>j; mapp[j]++;
	}

	for(const auto &p: mapp){
		if(mapp.count(n - p.first) && p.first*2 != n) {printf("%d %d\n", p.first, n - p.first); return 0;}
		else if(p.second >= 2 && p.first*2 == n) { printf("%d %d\n", p.first, p.first); return  0;}
	}
	cout<<"No Solution";
}

 
