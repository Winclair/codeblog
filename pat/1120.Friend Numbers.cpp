#include<iostream>
#include<string>
#include<set>
#include <cstdio>

using namespace std;

int digitsum(string num){
	int k = 0;
	for(auto s: num) k += (s - '0');
	return k;
}

int main() {
	int n; cin >>n;
	set<int> id;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		int ds = digitsum(s);
		id.insert(ds);
	}

	cout << id.size() << endl;
	auto it = id.begin();
	cout << *it++;
	for (; it != id.end(); ++it)
		cout << " " << *it;

}
