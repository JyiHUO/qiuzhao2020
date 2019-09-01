//
// Created by 霍俊毅 on 31/08/2019.
//

#include "iostream"
#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string S) {
    stack<pair<int, int>> res; // {sum_res, class}
    stack<pair<char, int>> check; // {char, class}
    for(char s:S){
      if(check.empty()){
        check.push({'(', 1});
        continue;
      }
      if(s == '(')check.push({'(', check.top().second+1});
      else{
        // have to pop the top in the end
        int c = check.top().second;
        if(res.empty())res.push({1, c});
        else{
          // add or multi
          int res_v = res.top().first;
          int res_c = res.top().second;
          if(res_c == c){res.pop(); res.push({res_v+1, c});} // add
          else if(c < res_c){ // multi
            res.pop();
            if(!res.empty() && res.top().second==c){
              int pre_res_v = res.top().first; // add with previous result
              res.pop();
              res.push({pre_res_v+res_v*2, c});
            }else
              res.push({res_v*2, c});
          }else{
            res.push({1, c});
          }
        }
        check.pop(); // maintain correct seq in check stack
      }
    }
    return res.top().first;
  }
};

int main(){
  string ss = "(()())";
  Solution s;
  cout << s.scoreOfParentheses(ss)<<endl;
}