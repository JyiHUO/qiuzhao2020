class Solution {
public:
  int removeBoxes(vector<int>& boxes) {
    int len = boxes.size();
    vector<vector<vector<int>>> memo(len, vector<vector<int>>(len, vector<int>(len, -1)));
    return dfs(0, len-1, 0, boxes, memo);
  }

  int dfs(int i, int j, int k, vector<int>& boxes, vector<vector<vector<int>>>& memo){
    if(i>j)return 0;
    if(memo[i][j][k]!=-1)return memo[i][j][k];

    while (j>i&&boxes[j]==boxes[j-1]){j--;k++;}
    int res = (k+1)*(k+1) + dfs(i, j-1, 0, boxes, memo);

    for(int m=i;m<j;m++){
      if(boxes[m] == boxes[j])
        res = max(res, dfs(i, m, k+1, boxes, memo)+dfs(m+1, j-1, 0, boxes, memo));
    }
    memo[i][j][k] = res;
    return memo[i][j][k];
  }
};