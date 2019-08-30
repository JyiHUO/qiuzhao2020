
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s=="")return 0;
    queue<char> q;
    unordered_map<char, int> m;
    int max_l = INT_MIN;
    for(char ss:s){
      if( (m.find(ss)==m.end()) || (m[ss]==0) ){
        m[ss] = 1;
        q.push(ss);
        int ql = q.size();
        max_l = max(max_l, ql);
      }else{
        while( m[ss]==1 ){
          m[q.front()] = 0;
          q.pop();
        }
        q.push(ss);
        m[ss] = 1;
        int ql = q.size();
        max_l = max(max_l, ql);
      }
    }
    return max_l;
  }
};