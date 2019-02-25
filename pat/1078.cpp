#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<tuple>
#include<set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <regex>

using namespace std;

vector<int> visit;
int m;

bool is_prime(int m){
	if(m == 1) return false;
	int md = sqrt(m);
	for (int i = 2; i <= md; ++i)
		if(m%i == 0) return false;
	return true;
}

int hpos(int d){
	int hi = d % m;
	if(!visit[hi]) { visit[hi] = 1; return hi;}
	else{
		int di = 1, p = (hi + 1)%m; 
		vector<int> again(m); again[hi] = 1;
		while( !again[p] ){
			if(!visit[p]) {visit[p] = 1; return p;} 
			else{  
				again[p] = 1; di++; 
				p = (hi + di*di) % m;
			}
		}
		return -1;  	
	}
}

int main(){
	int n; cin >> m >> n;
	while(!is_prime(m)) m++;
	visit.resize(m);
	for (int i = 0; i < n; ++i){
		int d; cin >> d;
		int hi = hpos(d);
		if(hi != -1) (i != n-1)? printf("%d ", hi): printf("%d", hi);
		else (i != n-1)? printf("%c ", '-'): printf("%c", '-');
	}
}

