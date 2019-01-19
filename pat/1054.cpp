#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
	int m, n;
	cin>>m>>n;
	map<int, int> mapp;
	int half = m*n/2;
  
	for (int i = 0; i < n*m; ++i){
		int color; cin>>color;
		mapp[color]++;
		if(mapp[color] > half){
			cout<<color; break;
		}
	}

}


