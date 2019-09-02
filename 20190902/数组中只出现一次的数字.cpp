class Solution {
public:
  void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    // O(n) time, O(1) space
    int tmp = 0;
    for(int n:data)
      tmp^=n;
    int idx=0;
    while((tmp&1)==0){
      tmp>>=1;
      idx++;
    }
    int a=0, b=0;
    for(int n:data){
      if(isBit(n, idx)==1)a^=n;
      else b^=n;
    }
    *num1=a;
    *num2=b;
  }
  int isBit(int num, int idx){
    while(idx){
      num>>=1;
      idx--;
    }
    return num&1;
  }
};