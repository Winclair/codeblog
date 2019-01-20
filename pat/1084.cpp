#include<iostream>
#include<string>
#include<set>
#include <cctype>
using namespace std;


int main(){
	set<char> set2, diff;
	string str1, str2;
	cin>>str1>>str2;
  	for(auto &s: str1) s = toupper(s);
  	for(auto s: str2) set2.insert(toupper(s));

  	for (auto s: str1)
        if (!set2.count(s))
        	if(!diff.count(s)){
        		diff.insert(s);
        		cout<<s;	
        	} 
}
 
