//
// Created by 霍俊毅 on 2019-08-17.
// O(nlogn)
//
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty())return 0;
    int n = nums.size();
    vector<vector<pair<int, int > >> dp(n);
    int max_so_far = 0;
    for(int i=0;i<n;i++){
      int left = 0;
      int right = max_so_far;
      while (left < right){
        int mid = (left + right) / 2;
        if(nums[i] > dp[mid].back().first)
          left = mid + 1;
        else
          right = mid;
      }
      int row = right - 1;
      int chance = 1;
      if(row >= 0){
        int l = -1;
        int r = dp[row].size()-1;
        while (l < r){
          double temp = (double(l) + double(r) ) / 2;
          int m = ceil(temp);
          if(nums[i] > dp[row][m].first)
            r = m - 1;
          else
            l = m;
        }
        chance = dp[row].back().second;
        if(nums[i] <= dp[row].front().first) // not the biggest
          chance -= dp[row][l].second;
      }
      dp[right].push_back({nums[i], (dp[right].empty()?chance:chance+dp[right].back().second)});
      if(right == max_so_far){
        max_so_far++;
      }
    }
    return dp[max_so_far-1].back().second;
  }
};

int main(){
  vector<int>v = {-85,62,-48,-81,-81,-44,98,15,62,-94};
  Solution s;
  cout << s.findNumberOfLIS(v)<< endl;
}