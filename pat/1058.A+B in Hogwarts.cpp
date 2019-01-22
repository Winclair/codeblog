#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int g1, s1, k1;
	int g2, s2, k2;
    scanf("%d.%d.%d", &g1, &s1, &k1); 
    scanf("%d.%d.%d", &g2, &s2, &k2);
    int g, s, k;
    int kup = 0, sup = 0;
    k = (k1 + k2)%29;
    if(k1 + k2 >= 29) kup = 1;
    s = (s1 + s2 + kup)%17;
    if(s1 + s2 + kup >= 17) sup = 1;
    g = g1 + g2 + sup;

    printf("%d.%d.%d", g, s, k);

}
