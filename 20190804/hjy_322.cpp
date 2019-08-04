//
// Created by 霍俊毅 on 2019-08-03.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int coinChange(vector<int>& coins, int amount)
  {
    vector<int> dp(amount+1, INT_MAX-100000);
    dp[0] = 0;
    for(int i=1; i<=amount; i++)
    {
      for(int j=0;j<coins.size();j++)
      {
        if(i-coins[j]>=0)
        {
          dp[i] = min(dp[i-coins[j]]+1, dp[i]);
        }
      }
    }
    if(dp[amount] != INT_MAX-100000)
      return dp[amount];
    return -1;
  }
};

int main(){
  vector<int> v = {1, 2, 5};
  Solution s;
  cout << s.coinChange(v, 11) << endl;
}