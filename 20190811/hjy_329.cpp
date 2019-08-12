//
// Created by 霍俊毅 on 2019-08-12.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty())return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> path(row, vector<int>(col, INT_MIN));
    int res = INT_MIN;
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        res = max(res, dfs(i, j, matrix, path));
      }
    }
    return res;
  }
  int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& path){
    if(path[row][col]!=INT_MIN)return path[row][col];
    vector<vector<int>> pos = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    int long_path = 0;
    for(auto p: pos){
      int new_row = row+p[0];
      int new_col = col+p[1];
      if( (0<=new_row&&new_row<matrix.size()&&0<=new_col&&new_col<matrix[0].size())
      && (matrix[new_row][new_col] > matrix[row][col]) )
        long_path = max(long_path, dfs(new_row, new_col, matrix, path));
    }
    path[row][col] = long_path+1;
    return path[row][col];
  }
};