#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<string> va = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> vb = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> ma = {{"tret", 0}, {"jan",1}, {"feb",2}, {"mar",3}, {"apr",4}, {"may",5}, {"jun",6}, {"jly",7}, {"aug",8}, {"sep",9}, {"oct",10}, {"nov",11}, {"dec", 12}};
map<string, int> mb = {{"", 0}, {"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6}, {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};

string etom(int t){
	string s1 = va[t%13];
	string s2 = vb[t/13];
	return ((s2 == "")? s1: ((s1 == "tret")? s2: s2+" "+s1));
}

int mtoe(string str){
	int len = str.size();
	if(len > 4) return mb[str.substr(0,3)]*13 + ma[str.substr(4,len-4)];
	else return ((mb.count(str))? mb[str]*13: ma[str]);	
	
}

int main(){
	int k; cin>>k;
	string sss; getline(cin, sss); // cut down the first line
	for (int i = 0; i < k; ++i){
		string s;  
		getline(cin, s);
		if(isdigit(s[0])) cout<<etom(stoi(s))<<endl;
		else cout<<mtoe(s)<<endl;
	}
	
}
 
