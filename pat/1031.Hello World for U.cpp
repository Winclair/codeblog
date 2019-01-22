#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;


int main(){
    string str; cin>>str;
    int len = str.size();
    int n2 = ((len + 2)%3 == 0)? (len + 2)/3 : (len + 2)/3 + 1;
    n2 = ((len + 2 - n2)%2 == 0)? n2: n2+1; 
    int n1 = (len + 2 - n2)/2;
    
    int i = 0;    
    for (; i < n1 - 1; ++i){
        cout<<str[i]; 
        for (int k = 0; k < n2-2; ++k) cout<<" ";
        cout<< str[len - 1 - i]<< endl;;         
    }
    
    for (int j = 0; j < n2; ++j) cout<< str[i+j];

}
