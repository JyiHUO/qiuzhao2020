#include <iostream>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <deque>
#include <time.h>
#include <random>
using namespace std;

// 方法一，随机选pivot，swap到最后，使用快排的方法 O(n) ~ O(n^2)
// 方法二，手写大顶堆O(n) + klog(n)
class Solution1 { // 随机快排，超时，当数据分布不好复杂度是O(n^2)
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    // random pivot
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    int left = 0;
    int right = input.size() - 1;
    while(true){
      uniform_int_distribution<> dis(left, right); // [left, right]
      int pivot = dis(gen);
      swap(input, pivot, right); // put pivot in the end
      int index = partition(input, left, right);
      if(index == k-1){
        break;
      }
      if(index>=k)right = index;
      else left = index;
    }
    vector<int> res;
    for(int i=0;i<k;i++){
      res.push_back(input[i]);
    }
    return res;
  }

  void swap(vector<int>&A, int i, int j){
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
  }

  int partition(vector<int>& A, int left, int right){
    int i = left;
    int pivot = A[right];
    for(int j=i;j<right;j++){
      if(A[j]<pivot){
        swap(A, i, j);
        i++;
      }
    }
    swap(A, right, i);
    return i;
  }

};

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res(k, 0);
    if(k > input.size())return vector<int>();
    heap_c(input); // O(n);
    for(int i=0;i<k;i++){ // klog(n)
      res[i] = get_top(input);
      pop_top(input);
    }
    // overall O(n)
    return res;
  }
  void heap_c(vector<int>&input){
    // smallest is in the top
    // create heap
    int s = (input.size()-2) / 2;
    if(s*2+2!=input.size()-1)input.push_back(INT_MAX); // for heap format, so that each node father node has two children node
    for(int i=s;i>=0;i--){
      heap_swap(input, i);
    }
  }

  int get_top(vector<int>&input){
    return input[0];
  }

  void pop_top(vector<int>&input){
    input[0] = INT_MAX;
    heap_swap(input, 0);
  }

  void heap_swap(vector<int>&input, int index){
    // swap the node with index in the heap and maintain the heap
    if(index>(input.size()-2)/2 ) return;
    if(input[index]<= input[index*2+1] && input[index]<=input[index*2+2])return;
    if(input[index*2+1] > input[index*2+2]){
      swap(input, index, index*2+2);
      heap_swap(input, index*2+2);
    }
    else {
      swap(input, index, index*2+1);
      heap_swap(input, index*2+1);
    }
  }

  void swap(vector<int>&A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
};


int main() {
  vector<int> v = {4,5,-11,-6,0,7,3,8,56,45,3,45,65,3,1,6,4,6,4,-1};
  int k = 4;
  Solution s;
  for(int n:s.GetLeastNumbers_Solution(v, k))cout<<n<<endl;
  return 0;
}