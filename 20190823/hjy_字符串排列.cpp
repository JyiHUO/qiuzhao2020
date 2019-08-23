class Solution {
public:
  vector<string> Permutation(string str) {
    // 基于回溯的算法，简单易懂
    int length = str.size();
    vector<string> res;
    if(length == 0)return res;
    sort(str.begin(), str.end()); // sort first
    deque<char> temp;
    vector<int> mark(length, 0);
    unordered_map<string, int > check_dup; // 注意测试样例aa,有重复结果，要用字典维护
    helper(res, temp, mark, str, check_dup);

    return res;
  }
  void helper(vector<string>& res, deque<char>&temp, vector<int>& mark, string& str, unordered_map<string, int>&check_dup){
    if(temp.size() == str.size()){
      // do copy tp result
      string r= "";
      for(int i=0;i<str.size();i++){
        char t = temp.front();
        r+=t;
        temp.pop_front();
        temp.push_back(t);
      }
      if(check_dup[r] == 1)return;
      res.push_back(r);
      check_dup[r] = 1;
      return;
    }
    for(int i=0;i<str.size();++i){
      if(mark[i] == 1)continue;
      temp.push_back(str[i]);
      mark[i] = 1;
      helper(res, temp, mark, str, check_dup);
      temp.pop_back();
      mark[i] = 0;
    }
  }
};