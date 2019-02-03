#include<iostream>
#include<vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i: a) cin >> i;
	int cnt = 0;
	for (int i = 1; i < n; ++i)
		if(i != a[i]){
			while(0 != a[0]){
				swap(a[0], a[a[0]]);
				++cnt;
			}
			if(i != a[i]){
				swap(a[0], a[i]);
				++cnt;
			}
		}
	for(auto &i: a) cout << i << " ";
	cout <<endl<< cnt;
	
}
