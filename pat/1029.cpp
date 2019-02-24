#include<vector>
#include <cstdio>

using namespace std;

/*
using IT = vector<int>::iterator;

int find_kth(IT b1, int m, IT b2, int n, int v1){
	if(m > n) return find_kth(b2, n, b1, m, v1);
	if(m == 0) return *(b2 + v1 - 1);
	if(v1 == 1) return min(*b1, *b2);

	int p1 = min(v1/2, m), p2 = p1+(n-m)/2+1;
	if ( *(b1+p1-1) < *(b2+p2-1) )
		return find_kth(b1+p1, m-p1, b2, p2, v1-p1);
	else if (*(b1+p1-1) > *(b2+p2-1) )
		return find_kth(b1, p1, b2+p2, n-p2, v1-p2);
	else
		return *(b1+p1-1);
}
*/
//解决内存超限
int main(){
	int m, n; vector<int> v1;
	scanf("%d", &m); v1.resize(m+1);
	for (int i = 0; i < m; ++i) scanf("%d", &v1[i]);
	v1[m] = 0x7fffffff;	
	scanf("%d", &n);
	int mp = (m+n+1)/2 - 1, i = 0;
	int count = -1;

	for (int j = 0; j < n; j++) {
        int temp; scanf("%d", &temp);
        while (v1[i] < temp) {
            count++;
            if (count == mp){ printf("%d", v1[i]); return 0;}
            i++;
        }
        count++;
        if (count == mp) {printf("%d", temp); return 0;}
    }

    while (i < m) {
        count++;
        if (count == mp){ printf("%d", v1[i]); return 0;}
        i++;
    }

}
