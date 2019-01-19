
#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


struct Man{
	int id, virtue, talent, total;	
};


bool comp(Man m1, Man m2){
	return (m1.total != m2.total)? m1.total > m2.total : 
		   ((m1.virtue != m2.virtue)? m1.virtue > m2.virtue : m1.id < m2.id);
}


int main(){
	int k, base, higher; 
	cin>>k>>base>>higher;

	vector<Man> sage, noble, fool, small;
	int n = 0;

	for (int i = 0; i < k; ++i){
		Man m; cin>>m.id>>m.virtue>>m.talent;
		m.total = m.virtue + m.talent;
		if(m.virtue >= base && m.talent >= base){
			n++;

			if(m.virtue >= higher ){
				if(m.talent >= higher) sage.push_back(m);
				else noble.push_back(m);
			}else{
				if(m.talent < higher && m.virtue >= m.talent ) fool.push_back(m);
				else small.push_back(m);
			}
		}
	}

	//sort all
	std::sort(sage.begin(), sage.end(), comp);
	std::sort(noble.begin(), noble.end(), comp);
	std::sort(fool.begin(), fool.end(), comp);
	std::sort(small.begin(), small.end(), comp);

	//out
	cout<<n<<endl;
	for(auto m: sage) printf("%d %d %d\n", m.id, m.virtue, m.talent);
	for(auto m: noble) printf("%d %d %d\n", m.id, m.virtue, m.talent);
	for(auto m: fool) printf("%d %d %d\n", m.id, m.virtue, m.talent);
	for(auto m: small) printf("%d %d %d\n", m.id, m.virtue, m.talent);


}
 
