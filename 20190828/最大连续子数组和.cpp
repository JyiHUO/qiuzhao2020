#include <deque>
#include <time.h>
#include <random>
using namespace std;

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    vector<int> arrsum(array.size(), 0);
    int result = INT_MIN;
    arrsum[0] = array[0];
    for(int i=1;i<array.size();i++){
      if(arrsum[i-1] < 0)
        arrsum[i] = array[i];
      else
        arrsum[i] = arrsum[i-1] + array[i];
      result = max(result, arrsum[i]);
    }
    return result;
  }
};


int main() {
  vector<int> v = {-2, -8, -1, -5, -9};
  Solution s;
  cout << s.FindGreatestSumOfSubArray(v) << endl;
  return 0;
}