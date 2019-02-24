#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;

struct node{
	int data, next;
};

int main(){
	int start, n;
	cin >> start >> n;
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

	vector<int> want_list, sep_list;
	vector<bool> visit(100000);
	for (int i = 0; i < cnt; ++i){
		int d = v[list[i]].data; 
		if(!visit[abs(d)]){
			want_list.push_back(list[i]);
			visit[abs(d)] = true;
		}else sep_list.push_back(list[i]); 
	}
	
	int ws = want_list.size(), ss = sep_list.size();	
	for (int i = 0; i < ws-1; ++i)
		printf("%05d %d %05d\n", want_list[i], v[want_list[i]].data, want_list[i+1]);
	if(ws) printf("%05d %d %d\n", want_list[ws-1], v[want_list[ws-1]].data, -1);
	

	for (int i = 0; i < ss-1; ++i)
		printf("%05d %d %05d\n", sep_list[i], v[sep_list[i]].data, sep_list[i+1]);
	if(ss) printf("%05d %d %d\n", sep_list[ss-1], v[sep_list[ss-1]].data, -1);
			
}
