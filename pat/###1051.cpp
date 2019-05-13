#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio> 
#include<set>
#include <algorithm>
#include<stack>

using namespace std;

int m, n, k;

bool ispopable(vector<int>& v){
	int current = 0;
	stack<int> stk;
    for(int j = 1; j <= n; j++) {
        stk.push(j);
        if(stk.size() > m) return false;
        while(!stk.empty() && stk.top() == v[current]) {
            stk.pop();
            current++;
        }
    }
	if(current == n) return true;
	return false;    
} 

int main() {
	cin >> m >> n >> k;
	for(int i=0;i<k;i++){
		vector<int> v(n);
		for(int j=0;j<n;j++) cin >> v[j];
		printf(ispopable(v)? "YES\n": "No\n");
	} 	  
}
