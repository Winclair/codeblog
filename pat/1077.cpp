#include<iostream>
#include<string>
#include <cstdio>
using namespace std;

string suffix(const string &s1, const string &s2){
	string s("");
	auto it1 = s1.rbegin(), it2 = s2.rbegin();
	for (; it1 != s1.rend() && it2 != s2.rend(); ++it1, ++it2){
		if(*it1 != *it2) break;
		s = *it1 + s;		
	}
	return s;
}

int main(){
	int n; cin >> n;
	string s1, s2; getline(cin, s1); //cut the end of first line
	getline(cin, s1); getline(cin, s2);
	string kuig = suffix(s1, s2);
	for (int i = 0; i < n-2; ++i){
		getline(cin, s1);
		kuig = suffix(kuig, s1); 	
	}
	if(kuig == "") cout << "nai";
	else cout << kuig; 
}
