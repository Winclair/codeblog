#include<iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	printf("%d=", n);
	if(n ==1 ) {cout << 1; return 0;}
    for(int i = 2; i <= n; i++){        
        if(n % i == 0){
        	int e = 1;
        	n /= i;
            while(n % i == 0){
            	e++; n /= i; 	
            }
            if(e == 1) cout << i;
            else printf("%d^%d", i, e);
            if(n != 1) printf("*");
            else break;
        }
    }

}
