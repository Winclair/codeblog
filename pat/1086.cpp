#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include <cstdio>

using namespace std;

// 1 2 3 4 5 6
// 3 2 4 1 6 5

void post_order(const vector<int> &pre, const vector<int> &in, vector<int> &want){
	int size = pre.size();
	if(size == 0) return;
	
	if(size == 1){ want.push_back(pre[0]); return;}
	
	auto pb = pre.begin(), ib = in.begin(), pe = pre.end(), ie = in.end();   
	auto it = find(ib, ie, pre[0]);
	int n = it - ib;
	
	post_order(vector<int>(pb + 1, pb + 1 + n), vector<int>(ib, it), want);
	post_order(vector<int>(pb + 1 + n, pe), vector<int>(it + 1, ie), want);
	want.push_back(pre[0]);
	
}



int main(){
	int n; cin >> n;
	vector<int> in, pre, want;
	stack<int> sk;

	for (int i = 0; i < 2*n; ++i){
		string s;
		cin >> s;
		if(s == "Push"){
			int k; cin >> k;
			pre.push_back(k);
			sk.push(k);
		}else{ 
			in.push_back(sk.top());
			sk.pop();
		}	 
	}


	post_order(pre, in, want);
	cout << want[0];
	for (int i = 1; i < n; ++i) 
		cout << " " << want[i];
	printf("\n");
}
