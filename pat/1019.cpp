#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;

bool is_palin(const vector<int> &v){
	int size = v.size();
	int i = 0, j = size - 1;
	for (;i < j; ++i, --j){
		if(v[i] != v[j]) return false;			
	}
	return true;
}

vector<int> conver(int num, int base){
	if(!num) return vector<int>{0};
	vector<int> v;
	while(num){
		v.push_back(num%base);
		num /= base;
	}
	return vector<int>(v.rbegin(), v.rend());
} 

int main(){
	int num, base;
	cin >> num >> base;
	vector<int> v = conver(num, base);
	if(is_palin(v)) printf("%s\n", "Yes");
	else printf("%s\n", "No");

	cout << v[0];
	for (unsigned int i = 1; i < v.size(); ++i)
		printf(" %d", v[i]);
}
