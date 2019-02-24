#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node{
	int data, next;
};

int main(){
	int start, n, k;
	cin >> start >> n >> k;
	vector<node> v(100000);
	for (int i = 0; i < n; ++i){
		int pos, data, next;
		cin >> pos >> data >> next;
		v[pos] = {data, next};
	}

	vector<int> list;
	int temp = start, cnt = 0;
	while (temp != -1){
		cnt++;
		list.push_back(temp);
		temp = v[temp].next;
	}

	vector<int> neg, kdown, kup, want;
	for (auto addr: list){
		int d = v[addr].data;
		if(d < 0) neg.push_back(addr);
		else if(d <= k) kdown.push_back(addr);
		else kup.push_back(addr);
	}
	want = neg; 
	copy(kdown.begin(), kdown.end(), back_inserter(want));
	copy(kup.begin(), kup.end(), back_inserter(want));
	
	for (int i = 0; i < cnt-1; ++i)
		printf("%05d %d %05d\n", want[i], v[want[i]].data, want[i+1]);
	if(cnt) printf("%05d %d %d\n", want[cnt-1], v[want[cnt-1]].data, -1);
			
}

