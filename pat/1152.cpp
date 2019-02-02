#include<iostream>
#include<string>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int num){
	for (int i = 2; i <= sqrt(num); ++i){
		if(num % i == 0) return false;
	}
	return true;
}


int main(){
	int L, k; cin >> L >> k;
	string s; cin >> s;
	string temp;
	for (int i = 0; i <= (L - k); ++i){
		temp = s.substr(i, k);
		if(is_prime(stoi(temp))){
			cout << temp;
			return 0;
		}
	}
	cout << 404;

}
