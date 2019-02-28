#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int inf = 100000000; 

int main(){
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	int e[n][n];
	vector<int> visit(n), dist(n), weight(n);
	fill(e[0], e[0]+n*n, inf);
	fill(dist.begin(), dist.end(), inf);
	for(int i=0; i<n; i++) scanf("%d", &weight[i]);
	for(int i=0; i<m; i++){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		e[a][b] = e[b][a] = c; 
	}
	
	vector<int> num(n), w(n);
	dist[c1] = 0; 
	w[c1] = weight[c1];
	num[c1] = 1;
	
	for(int i = 0; i < n; i++) {
        // get min_node in dist
		int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(!visit[j] && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        if(u == -1) break;
        visit[u] = 1;
        // update node
		for(int v = 0; v < n; v++) {
            if(!visit[v] && e[u][v] != inf) {
                if(dist[u] + e[u][v] < dist[v]) {
                    dist[v] = dist[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dist[u] + e[u][v] == dist[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    
    printf("%d %d", num[c2], w[c2]);
    
}
