//
// Created by 霍俊毅 on 2019-08-11.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int mergeStones(vector<int>& stones, int K) {
    int n = stones.size();
    if( (n-1)%(K-1) ) return -1;
    vector<int> presum(n+1, 0);
    for(int i=0;i<stones.size();i++)
      presum[i+1] = presum[i] + stones[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K+1, 100000)) );
    for(int i=0;i<n;i++)dp[i][i][1] = 0;


    for(int l=2;l<=n;l++){ // problem length
      for(int i=0;i<=n-l;i++){ // start
        int j = i + l - 1;
        for(int k=2;k<=K;k++){ // piles
          for(int mid=i;mid<j;mid+=K-1){
            dp[i][j][k] = min(dp[i][j][k], dp[i][mid][1]+dp[mid+1][j][k-1]);

            dp[i][j][1] = dp[i][j][K] + presum[j+1] - presum[i];
          }
        }
      }
    }
    return dp[0][n-1][1];
  }
};