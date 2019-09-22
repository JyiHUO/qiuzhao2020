//
// Created by 霍俊毅 on 22/09/2019.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

// 哈弗曼树解法
class Solution {
public:
  int minBuildTime(vector<int>& blocks, int split) {
    priority_queue<int, vector<int>, greater<int>> q;
    for(int n:blocks)q.push(n);
    while (q.size()>1){
      int n1 = q.top();
      q.pop();
      int n2 = q.top();
      q.pop();
      q.push(max(n1, n2)+split);
    }
    return q.top();
  }
};