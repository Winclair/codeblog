#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cstdio>
using namespace std;


struct Peo{
    int id, ge, gi, total;
    vector<int> choice;
};

bool cmp(Peo& p1, Peo& p2) {
    return ((p1.total != p2.total)? p1.total > p2.total : p1.ge > p2.ge);
}

int main(){
	int n_appli, n_sch, n_choi;
	cin>>n_appli>>n_sch>>n_choi;
	
	vector<int> quota;
	for (int i = 0; i < n_sch; ++i){
		int n; cin>>n; quota.push_back(n);
	}

	vector<Peo> all_peo;
	for (int i = 0; i < n_appli; ++i){
		Peo p; cin>>p.ge>>p.gi;
		p.total = p.ge + p.gi; p.id = i;
		for (int j = 0; j < n_choi; ++j){
			int n; cin>>n; p.choice.push_back(n);
		}
		all_peo.push_back(p);
	}

	sort(all_peo.begin(), all_peo.end(), cmp);
	vector<vector<Peo>> admitted(n_sch);
	for(auto &p: all_peo)
		for(auto sch_id: p.choice){
			if(quota[sch_id]) {
				admitted[sch_id].push_back(p);
				quota[sch_id]--; break;
			}else {
				Peo last = *(admitted[sch_id].rbegin());
				if(last.total == p.total && last.ge == p.ge) {admitted[sch_id].push_back(p); break;} 
			}
		}


	for(auto &ps: admitted){
		sort(ps.begin(), ps.end(), [](Peo &p1, Peo &p2){return p1.id < p2.id;});
		for(auto p = ps.begin(); p != ps.end(); p++){
			if(p != ps.begin()) cout<<" ";
			cout<<p->id;
		}
		cout<<endl;
	}				
	
}
