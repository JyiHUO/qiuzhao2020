#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> left(col, 0);
    vector<int> right(col, col);
    vector<int> height(col, 0);
    int square = 0;
    for(int i=0;i<row;i++){
      // for height
      int cur_r = col;
      int cur_l = 0;
      for(int j=0;j<col;j++){
        if (matrix[i][j]=='1')height[j]++;
        else height[j] = 0;
      }
//      cout << "height: ";
//      pm(height);
      // for left
      for(int j=0;j<col;j++){
        if(matrix[i][j]=='1')left[j]=max(cur_l, left[j]);
        else{left[j]=0;cur_l=j+1;}
      }
//      cout<<"left: ";
//      pm(left);
      // for right
      for(int j=col-1;j>=0;j--){
        if(matrix[i][j]=='1')right[j]=min(cur_r, right[j]);
        else{right[j]=col;cur_r=j;}
      }
//      cout<<"right: ";
//      pm(right);
      // for square
      for(int j=0;j<col;j++)
        square = max(square, (right[j] - left[j])*height[j]);
    }
    return square;
  }

  void pm(vector<int> &m){
    for(int i : m)
      cout << i<<" ";
    cout << endl;
  }

};