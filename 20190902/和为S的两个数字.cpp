class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int res_v = INT_MAX;
    vector<int> res;
    if(array.size()==0)return res;
    int left = 0;
    int right = int(array.size())-1;
    while(left!=right){
      if(array[left]+array[right]==sum){
        if(res_v>array[left]*array[right]){
          res_v = array[left]*array[right];
          res = {array[left], array[right]};
        }
        right--;
      }else if(array[left]+array[right]>sum)right--;
      else left++;
      cout << left<<endl;
    }
    return res;
  }
};