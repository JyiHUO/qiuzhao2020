//
// Created by 霍俊毅 on 2019-08-20.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if(nums.empty())return 0;
    int res = INT_MIN;
    int cumsum = 0;
    for(auto n:nums){
      cumsum+=n;
      res = max(cumsum, res);
      if (cumsum < 0)cumsum = 0;
    }
    return res;
  }
};