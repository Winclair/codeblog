#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

vector<int> father, hobby(1001);

int find_ftr(int x){
	if(father[x] != x) father[x] = find_ftr(father[x]);
	return father[x]; 
}

void uniset(int x, int y){
	father[find_ftr(x)] = find_ftr(y);
}

int main(){
	int n; cin >> n;
	father.resize(n+1);
	for(int i=1; i<n+1;i++) father[i] = i;
	
	for(int i=1; i<n+1;i++){
		int k; scanf("%d:", &k);
		for(int j=0; j<k;j++){
			int h; cin >> h;
			if(!hobby[h]) hobby[h] = i;
			else uniset(hobby[h], i); 		
		}
	}
	
	map<int, int> stat;
	for(int i=1; i<n+1;i++) stat[find_ftr(i)]++;
	
	multiset<int> out; 
	for(auto p: stat) out.insert(p.second); 
	printf("%d\n", out.size());
	auto it = out.rbegin();
	cout << *it++;
	for(;it!=out.rend();it++) printf(" %d", *it);
	 
}
