#include<iostream>
#include<map>
#include <cstdio>


using namespace std;

int main(){
	double odd = 1;
	map<int, char> dict = {{0,'W'}, {1, 'T'}, {2, 'L'}};
	for (int i = 0; i < 3; ++i){
		double temp = 0; int which;
		for (int j = 0; j < 3; ++j){
			double bet; cin >> bet;
			if(bet > temp){
				which = j;
				temp = bet;
			}
		}
		odd *= temp;
		cout << dict[which] << " ";
	}
	printf("%.2f", (odd*0.65 - 1)*2);
}
