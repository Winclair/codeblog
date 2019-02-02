#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;

int main(){
	int n; cin >> n;
	vector<double> v(n+1);
	for (int i = 1; i <= n; ++i) cin >> v[i];
	double total = 0;
	for (int i = 1; i <= n; ++i) total += v[i]*i*(n-i+1);   
	printf("%.2f\n", total);
}
