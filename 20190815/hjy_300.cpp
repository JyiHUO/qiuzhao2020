//
// Created by 霍俊毅 on 2019-08-16.
// O(nlogn)
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0)return 0;
    int max_s = 1;
    vector<int>tail(nums.size(), 0);
    tail[0] = nums[0];
    for(int i=1;i<nums.size();i++){
      int l = -1;
      int r = max_s;
      while(r-l>1){
        int m = (l+r)/2;
        if(tail[m]==nums[i])r=m;
        else if(tail[m]<nums[i])l=m;
        else r=m;
      } // the true number always in (l, r). It is the best way to define binary search problem
      if(l == -1)tail[0] = nums[i];
      else if(r == max_s){tail[max_s]=nums[i];max_s++;}
      else tail[r] = nums[i];
    }
    return max_s;
  }
};

int main(){
  Solution s;
  vector<int> nums = {10,9,2,5,3,7,101,18};
  cout << s.lengthOfLIS(nums) << endl;
}