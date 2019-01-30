#include<iostream>
#include<map>
#include<set>
#include <cstdio>
#include <cmath>

using namespace std;


bool is_prime(int num){
	for (int i = 2; i <= sqrt(num); ++i){
		if(num % i == 0) return 0;
	}
	return 1;
}

int main(){
	int k; cin >> k;
	map<int, int> dict;
	for (int i = 0; i < k; ++i){
		int id; cin >> id;
		dict[id] = i+1;
	}
	int n; cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i){
		int id; cin >> id;
		if(!dict.count(id)) printf("%04d: Are you kidding?\n", id);
		else if(s.count(id)) printf("%04d: Checked\n", id);
		else if(dict[id] == 1) printf("%04d: Mystery Award\n", id);
		else if(is_prime(dict[id])) printf("%04d: Minion\n", id);
		else printf("%04d: Chocolate\n", id);
		s.insert(id);
	}
	
}
 
