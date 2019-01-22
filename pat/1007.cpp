#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
  int k; cin>>k;
  vector<int> nums;
  for (int i = 0; i < k; ++i){
    int n; cin>>n;
    nums.push_back(n);
  }

  int n1 = nums[0];
  int maxx = -1, summ = 0, first = n1,  last = n1;
  int beg = n1, endd = n1;
  
  for(auto n : nums){
    if(summ > 0){
      summ += n; last = n;
    }else{ summ = n; first = last = n;}
    if(summ > maxx) {
    	maxx = summ;
    	beg = first;
    	endd = last;
    }
  }
//out
  if(maxx < 0) printf("%d %d %d\n", 0, nums[0], nums[k-1]); 
  else printf("%d %d %d\n", maxx, beg, endd); 
}
