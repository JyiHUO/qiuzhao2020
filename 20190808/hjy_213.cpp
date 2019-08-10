//
// Created by 霍俊毅 on 2019-08-10.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
      if(nums.empty())return 0;
    int N = nums.size();
      if(N==1)
      return nums[0];
    vector<int> dp1(N, 0);
    vector<int> dp2(N, 0);

    // if the first house was robbed
    dp1[0] = nums[0];
    dp1[1] = dp1[0];
    for(int i=2;i<N-1;i++){
      dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
    }


    // if the first one was not robbed
    dp2[0] = 0;
    for(int i=1;i<N;i++){
      if(i-2 <0)
        dp2[i] = max(dp2[i-1], nums[i]);
      else
        dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
    }
    return max(dp1[N-2], dp2[N-1]);
  }
};