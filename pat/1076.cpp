#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<vector<int>> follow;
vector<int> visit;

int bfs(int id, int level){
	if(!level) return 0;
	vector<int>v = {id};
	visit[id] = 1;
	int size = 1, total = 0;
	while(size && level){
		vector<int> temp;
		for(auto i: v)
			for(auto f: follow[i])
				if(!visit[f]){ 
					temp.push_back(f);
					total++;
					visit[f] = 1;
				}
		v = temp;
		size = temp.size();
		level--;	
	}
	return total; 
}

int main() {
	int n, level; cin >> n >> level;
	follow.resize(n+1);
	visit.resize(n+1);
	for (int i = 1; i < n+1; ++i){
	 	int m; cin >> m;
	 	for (int j = 0; j < m; ++j){
	 		int u; cin >> u;
	 		follow[u].push_back(i);
	 	}
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i){
		fill(visit.begin(), visit.end(), 0);
		int id; cin >> id;
		printf("%d\n", bfs(id, level));
	} 
}

/*
void dfs(int id, int level, int &total){
	if(!level) return ;
	if(!visit[id]) total++;
	visit[id] = 1;
	for(auto f: follow[id]) dfs(f, level - 1, total);
}

int main() {
	int n, level; cin >> n >> level;
	follow.resize(n+1);
	visit.resize(n+1);
	for (int i = 1; i < n+1; ++i){
	 	int m; cin >> m;
	 	for (int j = 0; j < m; ++j){
	 		int u; cin >> u;
	 		follow[u].push_back(i);
	 	}
	}
	int total = 0; 	
	int k; cin >> k;
	for (int i = 0; i < k; ++i){
		fill(visit.begin(), visit.end(), 0);
		int id; cin >> id;
		total = 0;
		dfs(id, level+1, total);
		printf("%d\n", total-1);
	} 
}
*/
