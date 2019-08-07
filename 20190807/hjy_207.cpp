#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> mark;
    for(int i=0;i<prerequisites.size();i++){
      graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for(const auto& kv:graph){
      int check = dfs(graph, mark, kv.first);
      mark[kv.first] = 0;
      if (check == 0)return false;
    }
    return true;
  }

  int dfs(unordered_map<int, vector<int>>&graph, unordered_map<int, int>&mark, int node){
    if(mark[node] == 1)return 0;
    mark[node] = 1;
    for(int i=0;i<graph[node].size();i++){
      int c = dfs(graph, mark, graph[node][i]);
      mark[graph[node][i]] = 0;
      if(c == 0)return 0;
    }
    return 1;
  }
};