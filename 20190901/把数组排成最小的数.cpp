class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    vector<string> str_num(numbers.size(), "");
    for(int i=0;i<numbers.size();i++)str_num[i] = to_string(numbers[i]);
    q_sort(str_num, 0, numbers.size()-1);
    string res = "";
    for(string s:str_num)
      res+=s;
    return res;
  }

  void q_sort(vector<string>&arr, int left, int right){
    if(left >= right)
      return;
    int pivot = partition(arr, left, right);
    q_sort(arr, left, pivot-1);
    q_sort(arr, pivot+1, right);
  }

  int partition(vector<string>&arr, int left, int right){
    string t = arr[right];
    int j = left;
    for(int i=left; i<right;i++){
      string f = arr[i]+t;
      string b = t+arr[i];
      if(f<b){
        swap(arr, j, i);
        j++;
      }
    }
    swap(arr, right, j);
    return j;
  }
  void swap(vector<string>& arr, int i, int j){
    string s = arr[i];
    arr[i] = arr[j];
    arr[j] = s;
  }
};