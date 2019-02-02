#include<iostream>
#include<string>
#include<tuple>
#include <cstdio>
#include <algorithm>

using namespace std;

tuple<int, int> sort_num(int num){
	string s = to_string(num);
	s += string(4 - s.size(), '0');
	sort(s.begin(), s.end());
	return make_tuple(stoi(s), stoi(string(s.rbegin(), s.rend())));
}


int main(){
	int num; cin >> num;
	auto t = sort_num(num);
	int small = get<0>(t), big = get<1>(t); 
	if(small == big){
		printf("%04d - %04d = %04d", big, small, 0000);
		return 0;
	}
	do{
		num = big - small; 
		printf("%04d - %04d = %04d\n", big, small, num);
		t = sort_num(num);
		small = get<0>(t);  big = get<1>(t); 

	}while(num != 6174);

}
