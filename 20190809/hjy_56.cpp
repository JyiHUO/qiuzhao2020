//
// Created by 霍俊毅 on 2019-08-10.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool static cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty())return vector<vector<int>>();
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> res;
    int n = intervals.size();
    res.push_back(intervals[0]);
    for(int i=1;i<n;i++){
      int temp_n = res.size();
      if(intervals[i][0]<=res[temp_n-1][1]) {
        if (res[temp_n - 1][1] < intervals[i][1])
          res[temp_n - 1][1] = intervals[i][1];
      }
      else
        res.push_back(intervals[i]);
    }
    return res;
  }

  void pm(const vector<vector<int>>& m){
    for(const auto& v:m){
      for(auto n:v){
        cout << n << " ";
      }
      cout << endl;
    }
  }
};