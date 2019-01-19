#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include <algorithm>
#include<iomanip>
using namespace std;


double similarity(const set<int> &s1, const set<int> &s2){
	int nc = 0, nt = s2.size();
	for(auto s: s1){
        if(s2.count(s)) nc++;
        else nt++;
    }
  return (double)nc / nt;
}


int main(){
	int k; cin>>k;
	vector<set<int> > v(k);

	for (int i = 0; i < k; ++i){
		int n; cin>>n;
		for (int j = 0; j < n; ++j){
			int num; cin>>num;
			v[i].insert(num);
		}
	}

	int k1; cin>>k1;
	for (int i = 0; i < k1; ++i){
		int n1, n2; cin>>n1>>n2;
		cout<<fixed<<setprecision(1)<<similarity(v[n1-1], v[n2-1])*100<<"%"<<endl;
	}

}
