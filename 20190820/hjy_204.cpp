//
// Created by 霍俊毅 on 2019-08-20.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    int  count = 0;
    vector<int> mark(n, 0);
    for(int i=2;i<n;i++){
      if(mark[i]==0){
        ++count;
        for(int j=2;j<n;j++){
          if(i*j >= n)break;
          mark[j*i] = 1;
        }
      }
    }
    return count;
  }
};