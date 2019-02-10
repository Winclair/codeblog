#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;


int main() {
	int n; cin >>n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int e = 0;
	for (int i = n-1; i >= 0; --i){
		if(v[i] > (n-i)) e = n-i;
	}
	cout << e;
}
