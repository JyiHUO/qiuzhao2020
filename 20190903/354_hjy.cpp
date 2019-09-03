//
// Created by 霍俊毅 on 03/09/2019.
//

#include "vector"
#include "iostream"
using namespace std;


class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if(envelopes.size() == 0)return 0;
    q_sort(envelopes, 0, envelopes.size()-1);

//    for(auto v:envelopes){
//      for(auto n:v)
//        cout << n<<" ";
//      cout << endl;
//    }
    // longest increase sequency
    vector<int> tail;
    int s = 1;
    tail.push_back(envelopes[0][1]);
    for(int i=1;i<envelopes.size();i++){
      int left = -1;
      int right = tail.size();
      while (right-left>1){
        int mid = (left+right)/2;
        if(tail[mid]==envelopes[i][1])right = mid;
        else if(tail[mid] > envelopes[i][1])right = mid;
        else left = mid;
      }
      if(right==tail.size()){
        tail.push_back(envelopes[i][1]);
        s++;
      }else tail[right]=envelopes[i][1];
    }
    //for(auto n:tail)cout<<n<<" ";
    return s;
  }

  void q_sort(vector<vector<int>>& arr, int left, int right){
    if(left>=right)return;
    int pivot = partition(arr, left, right);
    q_sort(arr, left, pivot-1);
    q_sort(arr, pivot+1, right);
  }

  int partition(vector<vector<int>>& arr, int left, int right){
    int j=left;
    vector<int>p = arr[right];
    for(int i=left;i<right;i++){
      if( (arr[i][0] < p[0]) || ( (arr[i][0] == p[0]) && (arr[i][1]>=p[1]) ) ){
        swap(arr, i, j);
        j++;
      }
    }
    swap(arr, j, right);
    return j;
  }

  void swap(vector<vector<int>>&arr, int i, int j){
    vector<int>t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
};