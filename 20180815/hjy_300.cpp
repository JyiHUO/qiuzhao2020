//
// Created by 霍俊毅 on 2019-08-16.
// O(nlogn)
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if(nums.empty())return 0;
    vector<int> tail;
    int size = 0;
    for(int x: nums){
      int left = 0;
      int right = tail.size();
      while (left<right){
        int m = (left + right) / 2;
        if (x > tail[m])
          left = m+1;
        else
          right = m;
      }
      if(right==tail.size()){
        size++;
        tail.push_back(x);
      } else{
        tail[right] = x;
      }
    }
    return size;
  }
};

int main(){
  Solution s;
  vector<int> nums = {10,9,2,5,3,7,101,18};
  cout << s.lengthOfLIS(nums) << endl;
}