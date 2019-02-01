#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;

int main(){
	int k; cin >> k;
	vector<int> v(k+1);
	for (int i = 0; i < k; ++i){
		int n; cin >> n;
		if(n > 0 && n <= k) v[n] = 1;
	}
	for (int i = 1; i < k+1; ++i)
		if(v[i] == 0){
			cout << i; return 0;
		}
	cout << k+1;	 
	

}
