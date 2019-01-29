#include<iostream>
#include<string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<string.h>

using namespace std;

struct Stu{
	int id;
	char name[10];
	int score;
};


int main(){
	int k, kind; cin>>k>>kind;

	vector<Stu> all;
	for (int i = 0; i < k; ++i){
		Stu s; cin >> s.id >> s.name >> s.score;
		all.push_back(s);
	}	
		
	switch(kind){
		case 1: sort(all.begin(), all.end(), [](Stu s1, Stu s2){ return s1.id < s2.id; });
		break;
		case 2: sort(all.begin(), all.end(), 
			[](Stu s1, Stu s2){ return ((s1.name != s2.name )? strcmp(s1.name, s2.name) <= 0 : s1.id < s2.id); }); 
		break;
		case 3: sort(all.begin(), all.end(), 
			[](Stu s1, Stu s2){ return ((s1.score != s2.score )? s1.score < s2.score : s1.id < s2.id); }); 
	}	

//out
	// cout<<all.size()<<endl;
	for(auto s : all) printf("%06d %s %d\n", s.id, s.name, s.score);
}
 
