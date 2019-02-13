#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;


int max_fsum = -1;
vector<int> exp_v, ans, fac_list;


void dfs(int k, int n, int fac_sum, int index){
	if(k == 0){
		if( (n == 0) && (fac_sum > max_fsum) ){
			max_fsum = fac_sum;
			ans = fac_list;
		}
		return ;
	}

	for (int i = index; i >= 1; --i){
		if(n - exp_v[i] >= 0){
			fac_list[k-1] = i;
			dfs(k-1, n - exp_v[i], fac_sum + i, i);
		}
	}
}


void init(int n, int p){
	int temp = 0, i = 1;
	while(temp <= n){
		exp_v.push_back(temp);
		temp = pow(i, p);
		i++;
	}
}


int main() {
	int n, k, p; cin >> n >> k >> p;
	fac_list.resize(k);
	init(n, p);
	int index = exp_v.size() - 1;
	
	dfs(k, n, 0, index);

	if(max_fsum == -1){
		printf("Impossible");
		return 0;
	}

	printf("%d = ", n);
	printf("%d^%d", ans[k-1], p);
	for (int i = k-2; i >= 0; --i)
		printf(" + %d^%d", ans[i], p);
}
