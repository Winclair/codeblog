#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>

using namespace std;

void level(const vector<int> &post, const vector<int> &in, map<int, int> &want, int index){
	int size = post.size();
	if(size == 0) return;
	want.insert({index, post[size - 1]});
	if(size == 1) return;
	
	auto pb = post.begin(), ib = in.begin(), pe = post.end(), ie = in.end();   
	auto it = find(ib, ie, post[size - 1]);
	int n = it - ib;
	level(vector<int>(pb, pb + n), vector<int>(ib, it), want, 2*index + 1);
	level(vector<int>(pb + n, pe - 1), vector<int>(it + 1, ie), want, 2*index + 2);
}


int main(){
	int n; cin >> n;
	vector<int> post(n), in(n);
	map<int, int> want;
	for (int i = 0; i < n; ++i) cin >> post[i];
	for (int i = 0; i < n; ++i) cin >> in[i];
	level(post, in, want, 0);
	cout << want[0];
	for(auto i: want)
		if(i.first == 0) continue; 
		else cout << " " << i.second;

}
