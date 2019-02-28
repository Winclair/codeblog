#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<tuple>
#include<set>
#include <algorithm>
#include <cstdio>


using namespace std;
const int inf = 10000, maxn = 510;

int n, m, c2, full;
int e[maxn][maxn];

vector<int> visit(maxn), dist(maxn), weight(maxn);
vector<vector<int>> prenode(maxn);
vector<int> path, temppath;
int send = inf, back = inf;

void init(){
	fill(e[0], e[0]+maxn*maxn, inf);
	fill(dist.begin(), dist.begin()+maxn, inf);
}

void dfs_path(int v){
	//cout << v<<"***";
	temppath.push_back(v);
	if(v == 0){

		int send_temp = 0, back_temp = 0;
		for(auto it = temppath.rbegin() + 1; it != temppath.rend(); ++it){
			if(weight[*it] > full/2) back_temp += weight[*it] - full/2;
			else{ 
				send_temp = (back_temp + weight[*it] > full/2) ? send_temp: send_temp + full/2 - (back_temp + weight[*it]); 
            	back_temp = (back_temp + weight[*it] > full/2)? (back_temp + weight[*it]) - full/2: 0; 
			}
		}
		if(send_temp < send || (send_temp == send && back_temp < back)){
			send = send_temp;
			back = back_temp;
			path = temppath;
		}
		temppath.pop_back();
		return ;
	}
	for(auto i: prenode[v])
		dfs_path(i);
	temppath.pop_back();
}

void dijkstra(){
	
	for(int i = 0; i < n+1; i++) {
		int u = -1, minn = inf;
        for(int j = 0; j < n+1; j++) {
            if(!visit[j] && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        if(u == c2) break;
        visit[u] = 1;
        // update node
		for(int v = 0; v < n+1; v++) {
            if(!visit[v] && e[u][v] != inf) {
                if(dist[u] + e[u][v] < dist[v]) {
					dist[v] = dist[u] + e[u][v];
                    prenode[v].clear();
                    prenode[v].push_back(u);
                }else if(dist[u] + e[u][v] == dist[v]) 
					prenode[v].push_back(u);
            }
        }
    }
}


int main(){
	cin >> full >> n >> c2 >> m;
	init();
	for (int i = 1; i < n+1; ++i) cin >> weight[i];
	for(int i=0; i<m; i++){
		int a, b, t; cin >> a >> b >> t;
		e[a][b] = e[b][a] = t; 
	}
	
	dist[0] = 0; 
	dijkstra();
	dfs_path(c2);

    printf("%d ", send);
    cout << *path.rbegin();
    for(auto it = path.rbegin()+1; it!=path.rend();it++) cout << "->" << *it;
    printf(" %d", back);
    return 0;	

}

