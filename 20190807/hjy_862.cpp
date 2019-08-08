//
// Created by 霍俊毅 on 2019-08-07.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int>& A, int K) {
      int n = A.size();
      int res = INT_MAX;
      vector<int> B(n+1, 0);
      for(int i=1;i<n+1;i++)
        B[i] = B[i-1]+A[i-1];
      deque<int> d;
      for(int i=0;i<n+1;i++){
        while (!d.empty()&&B[i]-B[d.front()]>=K){
          res = min(res, i-d.front());
          d.pop_front();
        }
        while (!d.empty()&&B[i]<=B[d.back()])d.pop_back();
        d.push_back(i);
      }
      return res<=n?res:-1;
  }
};

int main(){
  vector<int> v = {1,2};
  int K = 4;
  Solution s;
  cout << s.shortestSubarray(v, K)<<endl;
}