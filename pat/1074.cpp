#include<iostream>
#include<vector>
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

	vector<int> index;
	int temp = start, cnt = 0;
	while (temp != -1){
		cnt++;
		index.push_back(temp);
		temp = v[temp].next;
	}

	vector<int> new_idx(cnt);
	int j = 1, ni = 0;
	while(j*k <= cnt){
		for (int i = j*k - 1; i >= (j-1)*k; --i, ++ni){
			new_idx[ni] = index[i];
		}
		j++;
	}
	for (int i = (j-1)*k; i < cnt; ++i, ++ni) new_idx[ni] = index[i];
	
	for (int i = 0; i < cnt-1; ++i)
		printf("%05d %d %05d\n", new_idx[i], v[new_idx[i]].data, new_idx[i+1]);
	printf("%05d %d %d\n", new_idx[cnt-1], v[new_idx[cnt-1]].data, -1);
		
}

