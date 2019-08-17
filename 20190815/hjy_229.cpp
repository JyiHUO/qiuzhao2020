//
// Created by 霍俊毅 on 2019-08-17.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    if(nums.empty())return vector<int>();
    int can1 = 0, c1 = 0, can2 = 1, c2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if(nums[i] == can1 )++c1;
      else if(nums[i] == can2)++c2;
      else if(c1 == 0){can1=nums[i],c1=1;}
      else if(c2 == 0){can2=nums[i],c2=1;}
      else{--c1,--c2;}
    }
    c1=0, c2=0;
    int s = nums.size()/3;
    vector<int> res;
    for(auto n:nums){
      if(n==can1)c1++;
      else if(n==can2)c2++;

    }
    if(c1>s)res.push_back(can1);
    if(c2>s)res.push_back(can2);
    return res;
  }
};

int main(){
  vector<int> v = {1,1,1,3,3,2,2,2};
  Solution s;
  cout << s.majorityElement(v)[1] <<endl;
}