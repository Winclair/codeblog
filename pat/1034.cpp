#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>

using namespace std;

int maxn = 26*26*26;
vector<int> visit(maxn, 1), ptime(maxn);
vector<vector<int>> link(maxn), gang;

int hash_name(string name){
	return (name[0] - 'A')*26*26 +
		   (name[1] - 'A')*26 +
		   (name[2] - 'A');
}

string hash_id(int id){
	return string("") + char(id/(26*26) + 'A') +
		   char((id/26)%26 + 'A') +
		   char(id%26 + 'A');
}

void dfs(int id, int gi){
	if(visit[id]) return ;
	visit[id] = 1;
	gang[gi].push_back(id);
	for(auto i: link[id]) dfs(i, gi);
}

int total_time(vector<int> &v){
	int t = 0;
	for(auto i: v) t += ptime[i];
	return t;
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i){
		string s1, s2; int t; 
		cin >> s1 >> s2 >> t;
		int id1 = hash_name(s1), id2 = hash_name(s2);
		link[id1].push_back(id2);
		link[id2].push_back(id1);
		ptime[id1] += t;
		ptime[id2] += t;
		visit[id1] = 0;
		visit[id2] = 0;
	}

	gang.resize(n);
	int gi = 0;

	for (int i = 0; i < maxn; ++i){
		if(visit[i]) continue;
		dfs(i, gi);	
		gi++;
	}
	
	map<int, int> gmap;
	int gnum = 0;
	for (int i = 0; i < gi; ++i){
		int size = gang[i].size();
		if(size > 2 && total_time(gang[i]) > 2*k){
			gnum++;
			auto cmp = [](int id1, int id2){ return ::ptime[id1] < ::ptime[id2];};
			auto it = max_element(gang[i].begin(), gang[i].end(), cmp);
			gmap[*it] = size;
		}
	}
	cout << gmap.size() << endl;
	for(auto g: gmap) cout << hash_id(g.first) << " " << g.second << endl; 
}
