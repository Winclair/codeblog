#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>

using namespace std;

int main(){
    int k; cin >> k;
    vector<unsigned int> cdist(k);
    for (int i = 0; i < k; ++i) cin >> cdist[i];
    
	vector<unsigned int> jto1_dist(k);
	for(int j = 1; j < k; ++j)
		jto1_dist[j] = jto1_dist[j-1] + cdist[j-1];  
	unsigned int dsum = jto1_dist[k-1] + cdist[k-1];

    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int p1, p2; cin >> p1 >> p2;
        if(p1 > p2) swap(p1, p2);
        unsigned int sum1 = jto1_dist[p2-1] - jto1_dist[p1-1];
        cout << min(dsum - sum1, sum1) << endl;
    } 

}
