class Solution {
public:
  int NumberOf1Between1AndN_Solution(int n)
  {
    int result = 0;
    long pos = 10;
    while(n > 0){
      long c = (n%pos) / (pos/10);
      long high = n / pos;
      if(c == 0)result += int(high* (pos/10));
      else if(c == 1)result += int(high*(pos/10) + (n - n/(pos/10)*(pos/10) ) + 1);
      else result += int((high+1)*(pos/10));
      pos*=10;
      if(pos/10 > n)break;
    }
    return result;
  }
};