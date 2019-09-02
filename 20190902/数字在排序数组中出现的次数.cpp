#include <iostream>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <deque>
#include <time.h>
#include <random>
using namespace std;

class Solution {
public:
  int GetNumberOfK(vector<int> data ,int k) {
    int left = bsl(data, k);
    int right = bsr(data, k);
    return right - left + 1;
  }
  int bsl(vector<int>&data, int k){
    int l = -1;
    int r = data.size();
    while(r-l>1){
      int mid = (r+l)/2;
      if(data[mid]==k)r=mid;
      else if(data[mid]>k)r=mid;
      else l=mid;
    }
    return r;
  }
  int bsr(vector<int>&data, int k){
    int l = -1;
    int r = data.size();
    while(r-l>1){
      int mid = (r+l)/2;
      if(data[mid]==k)l=mid;
      else if(data[mid]>k)r=mid;
      else l=mid;
    }
    return l;
  }
};


int main() {
  Solution s;
  vector<int> data = {1,2,3,4,5,5,5,5,6,7,8};
  cout<<s.GetNumberOfK(data, 9)<<endl;
  return 0;
}