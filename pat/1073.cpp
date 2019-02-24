#include<iostream>
#include<string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	string s; cin >> s;
	auto ie = find(s.begin(), s.end(), 'E');
	int ep = stoi(string(ie+1, s.end()));
	string base = s[1] + string(s.begin()+3, ie);
	if(ep < 0) base = "0." + string(abs(ep) - 1, '0') + base;
	if(ep > 0){
		int len = base.size() - 1;
		if(ep >= len) base += string(ep - len, '0');
		else base.insert(ep+1, "."); 
	}
	string sb = (s[0]=='-')?"-" : "";
	cout << sb << base;		
}
