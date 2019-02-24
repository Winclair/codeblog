#include<iostream>

using namespace std;

int acount_1(int num){
    int cnt = 0, i = 1;
    int pos, high, low;
    while(num/i != 0){
        high = num/(i*10);
        low = num - (num/i)*i;
        pos = (num/i)%10;
        if(pos == 0) cnt += high*i;
        if(pos == 1) cnt += high*i + low + 1;
        if(pos > 1) cnt += (high+1)*i;
        i = i*10;
    }
    return cnt;
}

int main(){
	int num; cin >> num;
	cout << acount_1(num);
}
