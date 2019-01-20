#include<iostream>
#include<string>
#include<map>
#include <cstdio>
using namespace std;


int main(){
	map<char, int> map1, map2;
	string str1, str2;
	cin>>str1>>str2;
  	for(auto &s: str1) map1[s]++;
  	for(auto &s: str2) map2[s]++;

  	int No = 0;
  	for (auto &p: map2){
  		if(p.second > map1[p.first] ) No += p.second - map1[p.first];  
  	}

  	if(No) printf("%s %d", "No", No);
  	else printf("%s %d", "Yes", str1.size() - str2.size());
}
