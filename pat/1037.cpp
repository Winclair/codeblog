#include<iostream>
#include<set>

using namespace std;



int main(){
	int k; cin >> k;
	multiset<int> cpn, cpp;
	for (int i = 0; i < k; ++i){
		int n; cin >> n;
		if(n > 0) cpp.insert(n);
		else cpn.insert(n);
	}

	int k1; cin >> k1;
	multiset<int> pdn, pdp;
	for (int i = 0; i < k1; ++i){
		int n; cin >> n;
		if(n > 0) pdp.insert(n);
		else pdn.insert(n);
	}
	long long total = 0;
	for (auto it = cpp.rbegin(), it2 = pdp.rbegin(); 
		 it != cpp.rend() && it2 != pdp.rend(); ++it, ++it2){
		total += (*it) * (*it2);
	}
	for (auto it = cpn.begin(), it2 = pdn.begin(); 
		 it != cpn.end() && it2 != pdn.end(); ++it, ++it2){
		total += (*it) * (*it2);
	}
	cout << total;

}
 
