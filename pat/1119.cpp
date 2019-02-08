#include<iostream>
#include<vector>
#include <cstdio>

using namespace std;


void inorder(const vector<int> &pre, const vector<int> &post, vector<int> &want, bool &flag){
	int size = pre.size();
	flag = true;
	if(size == 0) return;
	if(size == 1){ want.push_back(pre[0]); return;}
	
	auto pob = post.begin(), pb = pre.begin(), poe = post.end(), pe = pre.end();   
	auto lit = find(pob, poe, pre[1]);
	int ln = lit - pob + 1;
	inorder(vector<int>(pb+1, pb + 1 + ln), vector<int>(pob, lit + 1), want, flag);
	
	want.push_back(pre[0]);

	if(ln + 1 == size) flag = false;
	else{
		inorder(vector<int>(pb+ln+1, pe), vector<int>(lit + 1, poe - 1), want, flag);
	}
}



int main(){
	int n; cin >> n;
	vector<int> post(n), pre(n), want;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	bool flag;	
	inorder(pre, post, want, flag);
	printf("%s\n", (flag ? "Yes": "No"));
  cout << want[0];
	for (int i = 1; i < n; ++i) 
		cout << " " << want[i];
	printf("\n");
	
}
