#include<iostream>
#include<string>
#include<vector>
#include <cstdio>

using namespace std;


int main() {
	string s; cin >> s;
	long long n = 0, nt = 0, nat = 0;
	for (auto it = s.rbegin(); it != s.rend(); ++it){
		switch(*it){
			case 'T': nt++; break;
			case 'A': nat += nt; break;
			case 'P': n += nat; break;
		}
	}
	cout << n % 1000000007 << endl;
}

