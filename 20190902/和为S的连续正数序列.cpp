class Solution {
public:
  vector<vector<int> > FindContinuousSequence(int sum) {
    deque<int> dq;
    vector<vector<int>> res;
    vector<int>presum(sum+1, 0);
    for(int i=1;i<=sum;i++)
      presum[i] = presum[i-1]+i;
    dq.push_back(1);
    for(int i=2;i<=sum;i++){
      int left = dq.front();
      int right = dq.back();
      int tmp = presum[right]-presum[left]+left;
      //cout <<tmp<<endl;
      if(tmp >= sum){
        while(tmp>sum){
          dq.pop_front();
          left = dq.front();
          right = dq.back();
          tmp = presum[right]-presum[left]+left;
        }
        if(tmp == sum){
          // copy
          int s = dq.size();
          vector<int>tv(s,0);
          for(int j=0;j<s;j++){
            tv[j] = dq.front();
            dq.push_back(dq.front());
            dq.pop_front();
          }
          res.push_back(tv);
        }
      }
      dq.push_back(i);
    }
    return res;
  }
};