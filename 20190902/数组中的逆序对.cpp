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
  int InversePairs(vector<int> data) {
    int res = 0;
    dm_sort(data, 0, data.size()-1, res);
    return res;
  }
  void dm_sort(vector<int>&data, int left, int right, int& res){
    if(left>=right)return;
    int mid = (left+right)/2;
    dm_sort(data, left, mid, res);
    dm_sort(data, mid+1, right, res);
    merge(data, left, mid, mid+1, right, res);
  }

  void merge(vector<int>&data, int lleft, int lright, int rleft, int rright, int& res){
    vector<int> tmp;
    int i = lleft;
    int j = rleft;
    while (i<=lright && j<=rright){
      if(data[i]>data[j]){
        res += lright - i + 1;
        res = res % 1000000007;
        tmp.push_back(data[j]);
        ++j;
      }else{tmp.push_back(data[i]);++i;}
    }
    while (i<=lright){tmp.push_back(data[i]);++i;}
    while (j<=rright){tmp.push_back(data[j]);++j;}
    for(int i=lleft,j=0;i<=rright;i++,j++)
      data[i] = tmp[j];
  }
};


int main() {
  Solution s;
  vector<int> v = {1};
  cout << s.InversePairs(v)<<endl;
  return 0;
}