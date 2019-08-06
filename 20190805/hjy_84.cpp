#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> t_h;
    stack<int> t_pos;
    int square = 0;
    for(int i=0;i<n;i++){
      if(t_h.empty()||t_h.top()<heights[i]){
        t_h.push(heights[i]);
        t_pos.push(i);
      } else{
        int temp_pos = 0;
        while (!t_h.empty()&&t_h.top()>=heights[i]){
          int temp_h = t_h.top();
          temp_pos = t_pos.top();
          square = max(square, (i - temp_pos)*temp_h);
          t_h.pop();
          t_pos.pop();
        }

        t_h.push(heights[i]);
        t_pos.push(temp_pos);
      }
    }
    while (!t_h.empty()){
      int temp_pos = t_pos.top();
      int temp_h = t_h.top();
      square = max(square, (n - temp_pos) * temp_h);
      t_h.pop();
      t_pos.pop();
    }
    return square;
  }
};