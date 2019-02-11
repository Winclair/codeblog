#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<vector<int>> link(1010);
vector<int> visit(1010);

void dfs(int node){
	visit[node] = 1;
	for(auto i: link[node]) 
		if(!visit[i]) dfs(i);
}


int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i){
	 	int a,b; scanf("%d %d", &a, &b);
	 	link[a].push_back(b);
	 	link[b].push_back(a);
	}
	vector<int> lost(k);
	for (int i = 0; i < k; ++i) scanf("%d", &lost[i]);

	for (auto ls: lost){
		fill(visit.begin(), visit.end(), 0);
		visit[ls] = 1; visit[0] = 1;
		int ant = 0;
		for (int j = 1; j <= n; ++j){
			if(!visit[j]){
				dfs(j);
				ant++;
			}
		}
		printf("%d\n", ant-1);

	 	
	} 	
}

