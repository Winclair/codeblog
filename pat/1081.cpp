#include<iostream>
#include <cstdio>
#include <cmath>

using namespace std;


long gcd(long n1, long n2){
	if(n1 == 0) return n2;
	if(n2 == 0) return n1;
	return gcd(n2, n1%n2);
}


int main(){
	int k; cin >> k;
	long inte = 0, nume = 0, deno = 1;
	for (int i = 0; i < k; ++i){
		long n, d; 
		scanf("%ld/%ld", &n, &d);
		nume = nume*d + n*deno;
		deno *= d;
		long c = nume/deno;
		nume -= c*deno;
		long g = gcd(abs(deno), abs(nume));
		deno /= g;
		nume /= g;  
		inte += c;
	}

	if(inte == 0){
		if(nume == 0) printf("%d", 0);
		else printf("%ld/%ld\n", nume, deno);
	}else{
		if(nume == 0) printf("%ld", inte);
		else printf("%ld %ld/%ld\n", inte, nume, deno);	
	} 	 
	
}
