//
// Created by 霍俊毅 on 2019-08-11.
//

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    if(graph.empty())return true;
    int n = graph.size();
    vector<int> color(n, 2); // 0 back color, 1 front color, 2 not visited

    // do first in node 0
    for(int i=1;i<n;i++){
      if(color[i]!=2)continue;
      if(!dfs(0, i, color, graph))return false;
    }
    return true;
  }
  bool dfs(int pre_color, int node, vector<int>&color, vector<vector<int>>&graph){
    if(color[node]==2){
      color[node] = !pre_color;
      for(int num:graph[node]){
        if(!dfs(!pre_color, num, color, graph))return false;
      }
      return true;
    }else{
      return color[node] != pre_color;
    }
  }
};