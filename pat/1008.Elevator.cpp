#include<iostream>
#include <cstdio>

using namespace std;

int main(){
	int n; cin >> n;
	int spend = 0, last = 0;

	for (int i = 0; i < n; ++i){
		int f; cin >> f;
		if(f > last) spend += 6*(f-last);
		else spend += 4*(last-f);
		last = f; 
	}
	spend += n*5;
	cout << spend;
}
