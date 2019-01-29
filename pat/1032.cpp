
//运行超时！！！
#include<iostream>
#include<string>
#include<map>
#include<tuple>
#include <cstdio>

using namespace std;

void link(int start, string &word, vector<int> &addr, map<int, tuple<char, int> > &dict){
	
	do{
		addr.push_back(start);
		auto t = dict[start];
		word += get<0>(t);
		if(get<1>(t) == -1) break;
		else start = get<1>(t); 
	}while(1);
}


int main(){
	int start1, start2, n; cin >> start1 >> start2 >> n;
	map<int, tuple<char, int> > dict;
	for (int i = 0; i < n; ++i){
		int beg, end; char c;
		cin >> beg >> c >> end;
		dict[beg] = make_tuple(c, end);
	}

	string word1, word2;
	vector<int> addr1, addr2;
	link(start1, word1, addr1, dict);
	link(start2, word2, addr2, dict);
	
	int k = 0;
	auto it1 = word1.rbegin(), it2 = word2.rbegin();
	for ( ; it1 != word1.rend() && it2 != word2.rend(); ++it1, ++it2){
		if(*it1 == *it2){
			++k; continue;
		} 
		else break; 			
	}
	if(k == 0) cout << -1;
	else printf("%05d", addr1[word1.size() - k]);

}


//空间换时间---by liuchuo

struct Node {
    char c;
    int next;
    bool flag;
}node[100000];


int main() {
    int s1, s2, n, b, e;
    scanf("%d%d%d", &s1, &s2, &n);
    char c;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &b, &c, &e);
        node[b] = {c, e, false};
    }
    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
