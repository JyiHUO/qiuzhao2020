//
// Created by 霍俊毅 on 2019-08-10.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> G(n+1, 0);
    G[0] = 1;
    G[1] = 1;
    for(int i=2;i<n+1;i++){
      for(int j=1;j<=i;j++){
        G[i] += G[j-1]*G[i-j];
      }
    }
    return G[n];
  }
};

int main(){
  int n = 4;
  Solution s;
  cout << s.numTrees(n) << endl;
}