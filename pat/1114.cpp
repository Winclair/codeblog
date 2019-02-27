#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int INF = 10000;

struct node{
	int mid = INF, amount;
	double estate, area;
};

vector<int> father, family(10000);

int find_ftr(int x){
	if(father[x] != x) father[x] = find_ftr(father[x]);
	return father[x]; 
}

void uniset(int x, int y){
	father[find_ftr(x)] = find_ftr(y);
}

bool cmp(node &f1, node &f2){
	double avgar1 = f1.area/f1.amount, avgar2 = f2.area/f2.amount;
	return ((avgar1 != avgar2)? avgar1 > avgar2: f1.mid < f2.mid);
}

int main(){
	int n; cin >> n;
	father.resize(n+1);
	for(int i=1; i<n+1;i++) father[i] = i;
	vector<node> v(n+1);
	
	for(int i=1; i<n+1;i++){
		node &fy = v[i]; 
		for(int j=0; j<3;j++){
			int id; cin >> id;
			if(id != -1){
				if(id < fy.mid) fy.mid = id;
				if(!family[id]) { family[id] = i; fy.amount++;}
				else uniset(family[id], i);
 			}
		}
		
		int k; cin >> k;
		for(int j=0; j<k;j++){
			int id; cin >> id;
			if(id < fy.mid) fy.mid = id;
			if(!family[id]) { family[id] = i; fy.amount++;}
			else uniset(family[id], i);
		}
		
		cin >> fy.estate >> fy.area; 
	}
	
	map<int, node> stat;
	for(int i=1; i<n+1;i++){
		node &temp = stat[find_ftr(i)];
		node &fy = v[i];
		if(fy.mid < temp.mid) temp.mid = fy.mid;
		temp.amount += fy.amount;
		temp.estate += fy.estate;
		temp.area += fy.area;
	} 

	vector<node> out; 
	for(auto p: stat) out.push_back(p.second);
	sort(out.begin(), out.end(), cmp);
	 
	printf("%d\n", out.size());
	for(auto fy: out){
		printf("%04d %d %.3f %.3f\n", fy.mid, fy.amount, fy.estate/fy.amount, fy.area/fy.amount);
	}
	 
}
