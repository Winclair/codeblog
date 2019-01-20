#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Testee{
	string name, id;
	int grade;
};

int main(){
	int k; cin>>k;
	vector<Testee> all;
	for (int i = 0; i < k; ++i){
		Testee te;
		cin>>te.name>>te.id>>te.grade;
		all.push_back(te);
	}
	int low, high; cin>>low>>high;

	sort(all.begin(), all.end(), [](Testee t1, Testee t2){return t1.grade > t2.grade;});
	auto b = find_if(all.begin(), all.end(), [&high](Testee t){return t.grade <= high;});
	auto e = find_if(all.rbegin(), all.rend(), [&low](Testee t){return t.grade >= low;});
	
	if(b == all.end() || e == all.rend()) cout<<"NONE";
	else for(auto it = b; it != e.base();it++) cout<<it->name<<" "<<it->id<<endl; 

}
