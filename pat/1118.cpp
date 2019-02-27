#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<int> father, pic(10001);

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
	int n_bird = 0;
	
	for(int i=1; i<n+1;i++){
		int k; cin >> k;
		for(int j=0;j<k;j++){
			int b; cin >> b;
			if(!pic[b]) {pic[b] = i; n_bird++;}
			else uniset(pic[b], i);
		}
	}
	
	map<int, int> stat;
	for(int i=1; i<n+1;i++) stat[find_ftr(i)]++;
	printf("%d %d\n", stat.size(), n_bird);
	 
	int m; cin >> m;
	for(int i=0; i<m;i++){
		int b1, b2; cin >> b1 >> b2;
		printf((father[pic[b1]] == father[pic[b2]])? "Yes\n" : "No\n");
	}
	 

}
