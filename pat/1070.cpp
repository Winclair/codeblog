#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Cake{
	double aver, amount, price;
};

int main(){
	int k; double total; 
	cin >> k >> total;
	vector<Cake> all(k);
	for (int i = 0; i < k; ++i)
		cin >> all[i].amount;
	for (int i = 0; i < k; ++i){
		cin >> all[i].price;
		all[i].aver = all[i].price / all[i].amount;
	}
	sort(all.begin(), all.end(), [](Cake c1, Cake c2){ return c1.aver > c2.aver;});
	
	double prof = 0;
	for (int i = 0; i < k; ++i){
		Cake c = all[i];
		if(total <= c.amount){
			prof += total * c.aver;
			break;
		}else{
			prof += c.price;
			total -= c.amount;
		}	
	}

	printf("%.2f", prof); 	
}
 
