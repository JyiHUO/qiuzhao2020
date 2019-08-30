class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> check;
    stack<char> dy;

    check = {{'}', '{'}, {']', '['}, {')', '('}};
    for(char ss:s){
      if(check.find(ss)==check.end()){
        dy.push(ss);
      }else{
        if(!dy.empty() && check[ss]==dy.top())
          dy.pop();
        else return false;
      }
    }
    return dy.size() == 0;
  }
};