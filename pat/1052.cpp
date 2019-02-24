#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node{
	int data, next;
};

int main(){
	int start, n;
	cin >> n >> start;
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

	if( cnt == 0){ printf("%d %d\n", 0, -1); return 0;}
	sort(list.begin(), list.end(), [&v](int a, int b){return v[a].data < v[b].data;});
	printf("%d %05d\n", cnt, list[0]);
	for (int i = 0; i < cnt-1; ++i)
		printf("%05d %d %05d\n", list[i], v[list[i]].data, list[i+1]);
	if(cnt) printf("%05d %d %d\n", list[cnt-1], v[list[cnt-1]].data, -1);
			
}

