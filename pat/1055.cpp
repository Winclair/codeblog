#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio> 
#include <algorithm>
#include<cstring>

using namespace std;

struct Richs{
	char name[10];
	int age, worth;
};

bool cmp(Richs r1, Richs r2){
	if(r1.worth != r2.worth) return (r1.worth > r2.worth);
	else if(r1.age != r2.age) return (r1.age < r2.age);   
	else return (strcmp(r1.name, r2.name) < 0);	
}


int main() {
	int n, k;
	cin >> n >>k;
	vector<Richs> rs(n);
	for(int i=0;i<n;i++)
		scanf("%s %d %d", rs[i].name, &rs[i].age, &rs[i].worth);
	sort(rs.begin(), rs.end(), cmp);
	
	for(int i=0;i<k;i++){
		int qn, amin, amax;
		cin >> qn >> amin >> amax;
		printf("Case #%d:\n", i+1);
		int j = 0;
		for(auto &r:rs){
			if(j == qn) break;
			if(r.age >= amin && r.age <= amax){
				printf("%s %d %d\n", r.name, r.age, r.worth);
				j++;
			}
		}
		if(j == 0) printf("None");
	}
	
}
