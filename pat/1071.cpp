#include<iostream>
#include<string>
#include<map>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;


int main(){
	string str; getline(cin, str);
	for(auto &s: str)
		if(isalnum(s)) s = tolower(s);
		else s = ' ';
	istringstream is(str);
	string word;
	map<string, int> count;
	while(is>>word) count[word]++;
	auto it = max_element(count.begin(), count.end(), 
		[](pair<string, int> p1, pair<string, int> p2 ){ return p1.second < p2.second; });
	cout<<it->first<<" "<<it->second;
	
}
