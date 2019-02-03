#include<iostream>
#include<string>
#include <cstdio>

using namespace std;

int main(){

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		long long ab = a+b;
		bool is;		
		if(a>0 && b>0 && ab<=0) is = true;
		else if(a<0 && b<0 && ab>=0) is = false;
		else is = (ab > c)? true : false ;
		printf("Case #%d: %s\n", i, (is? "true":"false") );
	}
}


