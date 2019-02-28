#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>


using namespace std;
const int inf = 1000000, maxn = 300;

int n, m, c2;

int e[maxn][maxn];
vector<int> visit(maxn), dist(maxn), weight(maxn);
vector<int> pathnum(maxn), prenode(maxn), happy(maxn), nodenum(maxn);

vector<string> path;
map<string, int> dict; 
vector<string> city; 

void init(){
	fill(e[0], e[0]+maxn*maxn, inf);
	fill(dist.begin(), dist.begin()+maxn, inf);
}

void get_path(int v){
	path.push_back(city[v]);
	if(v == 0) return ;
	get_path(prenode[v]);
}

int main(){
	cin >> n >> m;
	city.resize(n);
	cin >> city[0];
	init();
	for (int i = 1; i < n; ++i){
		string c; int h;
		cin >> c >> h;
		weight[i] = h;
		dict[c] = i;
		city[i] = c;
	}
	
	for(int i=0; i<m; i++){
		string sa, sb; int co; 
		cin >> sa >> sb >> co;
		int a = dict[sa], b = dict[sb];
		e[a][b] = e[b][a] = co; 
	}
	
	dist[0] = 0; pathnum[0] = 1;
	c2 = dict[string("ROM")];

	for(int i = 0; i < n; i++) {
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
                    prenode[v] = u;
					happy[v] = happy[u] + weight[v];
					nodenum[v] = nodenum[u] + 1;
					pathnum[v] = pathnum[u];
                }else if(dist[u] + e[u][v] == dist[v]){
                	pathnum[v] += pathnum[u];
                	if(happy[v] < happy[u] + weight[v]){
                		happy[v] = happy[u] + weight[v];
                    	prenode[v] = u;
                    	nodenum[v] = nodenum[u] + 1;	
                	}else if(happy[v] == happy[u] + weight[v] ) 
		                 if(double(happy[v])/nodenum[v] < double(happy[u] + weight[v])/(nodenum[u]+1)){
		                 	prenode[v] = u;
                    		nodenum[v] = nodenum[u] + 1;
		                 } 
            	}
            }
        }
    }
 
    get_path(c2);
    printf("%d %d %d %d\n", pathnum[c2], dist[c2], happy[c2], happy[c2]/nodenum[c2]);

    cout << *path.rbegin();
    for(auto it = path.rbegin()+1; it!=path.rend();it++) cout << "->" << *it;

}

