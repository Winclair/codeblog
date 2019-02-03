#include<iostream>
#include<string>
#include <cstdio>
#include <algorithm>

using namespace std;

string addlll(string s1, string s2){
	if(s1.size() < s2.size()) swap(s1, s2);
	int len1 = s1.size(), len2 = s2.size();
	s2 = string(len1 - len2, '0') + s2;
	int up = 0;
	string result = "";
	for (int i = len1 - 1; i >= 0; --i){
		int n1 = s1[i] - '0', n2 = s2[i] - '0';
		result = to_string((n1+n2+up)%10) + result;
		up = (n1+n2+up) / 10; 			
	}
	if(up == 1) result = "1" + result;
	return result;
}


int main(){
	
	string n;  int k;
	cin >> n >> k;
	int i = 0;
	while(i < k){
		string rn = n;
		reverse(rn.begin(), rn.end());
		if(n == rn) break;
		else{
			n = addlll(n, rn);
			++i;
		}
	}
	cout << n << endl << i;
}

