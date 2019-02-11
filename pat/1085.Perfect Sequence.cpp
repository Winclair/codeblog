#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n; long long p; cin >> n >> p;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int ml = 1;
	// 1 2 3 4 5 6 7 8 9 20, p=8
	for (int i = 0; i < n-ml; ++i)
		for (int j = i + ml; j < n; ++j)
			if(v[i] * p >= v[j]) ml++;
			else break; 
	cout << ml;
}
