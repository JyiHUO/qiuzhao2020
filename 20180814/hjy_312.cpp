//
// Created by 霍俊毅 on 2019-07-01.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    vector<int> new_nums;
    new_nums.push_back(1);
    for(auto n:nums)if(n>0)new_nums.push_back(n);
    new_nums.push_back(1);
    int n = new_nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    // bottom up set the k for limitation, so I can use the sub problem to calculate the whole problem
    for(int k=2;k<n;k++){
      for(int i=0;i+k<n;i++){
        int j = i + k;
        for(int z=i+1;z<j;z++){
          dp[i][j] = max(dp[i][j], new_nums[i]*new_nums[z]*new_nums[j]+dp[i][z]+dp[z][j]);
        }
      }
    }
    return dp[0][n-1];
  }
};