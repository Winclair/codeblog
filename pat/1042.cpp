#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <cstdio>

using namespace std;

int main(){
	vector<string> 
	cards = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
			 "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	 		 "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
			 "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
	map<int, string> dict, temp;
	int i = 1; 
	for(auto c: cards){
		dict[i] = c;
		++i;
	}

	int n; cin >> n;
	vector<int> order(54); 
	for(auto &v: order) cin >> v;

	for (int i = 1; i <= n; ++i){
		swap(dict, temp);
		int j = 0;
		for(auto &p: temp){
			dict[order[j]] = p.second;
			++j;
		} 
	}

	cout << dict[1];
	for (int i = 2; i <= 54; ++i) cout << " " << dict[i];
}
