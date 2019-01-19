#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include <algorithm>

using namespace std;

//string 到 int 的映射
int hash_name(string name){
	return (name[0] - 'A') * 26 * 26 * 10\
		+ (name[1] - 'A') * 26 * 10\
		+ (name[2] - 'A') * 10\
		+ (name[3] - '0');
}


int main(){
	int k, n;
	cin>>k>>n;

	map<int, set<int> > course;

	for (int i = 0; i < n; ++i){
		int index, num;
		cin>>index>>num;
		for (int j = 0; j < num; ++j){
			string name; cin>>name; 
			int hname = hash_name(name);
			course[hname].insert(index);
		}
	}
	
	// out
	for (int i = 0; i < k; ++i){
		string name; cin>>name;
		cout<<name;
		int hname = hash_name(name);

		if(course.count(hname)){
			set<int> s = course[hname];
			cout<<" "<<s.size();
			for(auto c : s) cout<<" "<<c;	
		}else cout<<" "<<0;
		cout<<endl;
	} 
	 
}

