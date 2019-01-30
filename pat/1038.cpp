#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool scmp(string s1, string s2){
	return stoll(s1+s2) < stoll(s2+s1);
}

int main(){
	int k; cin >> k;
	vector<string> v(k);
	for (int i = 0; i < k; ++i) cin >> v[i];
	sort(v.begin(), v.end(), scmp);
	
	int i = 0;
	for (; i < k; ++i) 
		if(stoll(v[i])) break;
	if(i<k){
		cout << stoll(v[i]);
		for (int j = i+1; j < k; ++j) cout << v[j];
	}else cout<<0;
}
