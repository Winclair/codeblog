#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int lssl(const string &s){
	string str("#"), temp("#");
	for(auto i: s) 
		str += (i + temp);
	
	int size = str.size();
	vector<int> p(size);   // p[i] is lssl which centre i.
	int ct = 0; int bd = 0;  // ct is centre position of lss that have calculated. 
	int ml = 1;                                 // bd is the position of lss' rigth border.     
	for (int i = 0; i < size; ++i){
		p[i] = (bd > i)? min(p[2*ct - i], bd - i + 1) : 1;
		while (i + p[i] < size && i - p[i] >= 0 && str[i + p[i]] == str[i - p[i]]) 
			p[i]++;
		if(p[i] >= ml){
			ct = i; bd = i + p[i] - 1;
			ml = p[i];
		}		
	}
	return (ml - 1);
}


int main(){
	string s; getline(cin, s);
	cout<<lssl(s);
}
 
