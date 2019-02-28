#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>


using namespace std;
const int inf = 10000, maxn = 510;

int n, m, c1, c2;

int e[maxn][maxn], w[maxn][maxn];
vector<int> visit(maxn), dist(maxn), cost(maxn), prenode(maxn);
vector<int> path;

void init(){
	fill(e[0], e[0]+maxn*maxn, inf);
	fill(w[0], w[0]+maxn*maxn, inf);
	fill(dist.begin(), dist.begin()+maxn, inf);
	fill(cost.begin(), cost.begin()+maxn, inf);
}

void get_path(int v){
	path.push_back(v);
	if(v == c1) return ;
	get_path(prenode[v]);
}

int main(){
	cin >> n >> m >> c1 >> c2;
	init();
	
	for(int i=0; i<m; i++){
		int a, b, l, c; scanf("%d %d %d %d", &a, &b, &l, &c);
		e[a][b] = e[b][a] = l; 
		w[a][b] = w[b][a] = c; 
	}
	
	dist[c1] = 0; cost[c1] = 0; 	
	for(int i = 0; i < n; i++) {
        // get min_node in dist
		int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(!visit[j] && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        
        if(u == c2) break;
        visit[u] = 1;
        // update node
		for(int v = 0; v < n; v++) {
            if(!visit[v] && e[u][v] != inf) {
                if(dist[u] + e[u][v] < dist[v]) {
                   
					dist[v] = dist[u] + e[u][v];
                    cost[v] = cost[u] + w[u][v];
                    prenode[v] = u;
                }else if(dist[u] + e[u][v] == dist[v] && cost[v] > cost[u] + w[u][v]) {
                	cost[v] = cost[u] + w[u][v];
                    prenode[v] = u;	
                }
            }
        }
    }
 
    get_path(c2);
    for(auto it = path.rbegin(); it!=path.rend();it++) printf("%d ", *it);
    printf("%d %d", dist[c2], cost[c2]);

}
