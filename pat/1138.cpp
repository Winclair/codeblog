#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n; cin >>n;
	vector<int> pre(n), in(n); 

	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> in[i];
	
	auto pb = pre.begin(), ib = in.begin(), pe = pre.end(), ie = in.end();   
	
	while((pe - pb) != 1){
		auto it = find(ib, ie, *pb);
		int n = it - ib;
		if(n) { pb = pb + 1; pe = pb + n; ie = it;}
		else { pb = pb + 1; ib = it + 1;}
	}
	cout << *pb;

}
