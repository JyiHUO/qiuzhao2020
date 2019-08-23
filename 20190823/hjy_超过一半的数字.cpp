class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size()==0)return 0;
    int c = 0;
    int n = INT_MIN;
    for(auto num:numbers){
      if(c == 0){
        n = num;
        c++;
      }else{
        if(n!=num)c--;
        else c++;
      }
    }
    c = 0;
    for(auto num:numbers)
    {
      if(n==num)
        c++;
    }

    if(c*2 > numbers.size()){
      return n;
    }

    return 0;
  }
};