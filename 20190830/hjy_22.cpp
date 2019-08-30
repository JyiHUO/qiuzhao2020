class Solution {
public:
  vector<string> generateParenthesis(int n) {
    stack<char> s; // check if the string is legal
    deque<char> d;
    int f_num = n;
    int b_num = n;
    vector<string> res;
    dfs(f_num, b_num, s, d, res);
    return res;
  }
  void dfs(int f_num, int b_num, stack<char>& s, deque<char>& d, vector<string>& res){
    if(f_num==0 && b_num==0){
      string res_s = "";
      int c = d.size();
      while (c--){
        res_s += d.front();
        d.push_back(d.front());
        d.pop_front();
      }
      res.push_back(res_s);
      return;
    }
    if(f_num!=0){
      --f_num;
      d.push_back('(');
      s.push('(');
      dfs(f_num, b_num, s, d, res);
      s.pop();
      d.pop_back();
      ++f_num;
    }
    if(!s.empty()&&b_num!=0){
      --b_num;
      char t = s.top();
      s.pop();
      d.push_back(')');
      dfs(f_num, b_num, s, d, res);
      d.pop_back();
      s.push(t);
      ++b_num;
    }
  }
};