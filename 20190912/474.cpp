class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int >>(m+1, vector<int>(n+1, 0)));
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // initialize
    // 根据背包九讲的说法，如果最后要求要达到约束条件，则初始化不符合规格的dp为负无穷大
//    for(int i=0;i<strs.size()+1;i++)
//      dp[i][0][0] = 0;

    for(int k=0;k<strs.size();k++){
      vector<int> v = r_one_zero(strs[k]);
      int ones = v[0];
      int zeroes = v[1];

//      cout<<"str[k-1]: "<<strs[k-1]<<endl;
//      cout <<"ones: "<<ones<<endl;
//      cout <<"zeros: "<<zeroes<<endl;
      for(int M=m;M>=0;M--){
        for(int N=n;N>=0;N--){
          if(M-zeroes>=0 && N-ones>=0){

            dp[M][N] = max(dp[M][N], dp[M-zeroes][N-ones]+1);

          }
        }
      }
    }
    return dp[m][n]>0?dp[m][n]:0;
  }

  vector<int> r_one_zero(string &s){
    int ones = 0;
    int zeroes = 0;
    for(char ss:s){
      if(ss=='1')ones++;
      else zeroes++;
    }
    return {ones, zeroes};
  }
};