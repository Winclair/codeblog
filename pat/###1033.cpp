#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<set>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;



int main(){
	double tank, dist, aver, station;
	cin >> tank >> dist >> aver >> station;
	map<double, double> sale;
	double start = 0;
	for (int i = 0; i < station; ++i){
	 	double p, d;
	 	cin >> p >> d;
	 	if(d == 0) start = p;
	 	sale[p] = d;
	} 

	if(!start){
		printf("The maximum travel distance = %.2f", 0);
		return 0;
	}
	if(dist > (aver*station*tank) ){ 
		printf("The maximum travel distance = %.2f", (aver*station*tank));
		return 0;
	}

	double curr = 0, run = tank*aver;
	double total = 0;
	double oil = 0;

	int flag = 0;
	while(curr < dist){
		flag = 0;
		for(const auto &s: sale){
			double d = s.second - curr;
			if(d > 0 && d <= run){
				if(s.first < start){
					total += (d/aver - oil)*start;
					curr = s.second;
					oil = 0;	
				}else{
					if(curr + run > dist){
						total += start * ((dist - curr)/aver - oil);
						curr = dist;	
					}else{
						total += start * (tank - oil);
						oil = tank - d/aver;
						curr = s.second;
					}	
				}
				start = s.first;
				flag = 1;
				break; 
			}	
		}
		if(!flag){
			total += start * ((dist - curr)/aver - oil);
			curr = dist;
		}
	}

	printf("%.2f", total);

}
 
