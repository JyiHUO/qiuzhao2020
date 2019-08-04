//
// Created by 霍俊毅 on 2019-08-03.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon)
  {
    int row = dungeon.size();
    int col = dungeon[0].size();
    vector<vector<int>> dp(row+1, vector<int>(col+1, INT_MAX)); // current
    dp[row][col-1] = 1;
    dp[row-1][col] = 1;

    for (int i=row-1;i>=0;i--)
    {
      for (int j=col-1;j>=0;j--)
      {
        int n = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
        if(n <= 0){
          dp[i][j] = 1;
        } else{
          dp[i][j] = n;
        }
      }
    }
    return dp[0][0];
  }
};
