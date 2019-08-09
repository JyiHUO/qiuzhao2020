#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<col;i++){
            vector<int> sums(row, 0);
            for(int j=i;j<col;j++){
                // k algorithm
                for(int s=0;s<sums.size();s++){
                    sums[s] += matrix[s][j];
                }
                // maximum subarray in sums
                int maxsub = INT_MIN;
                int cursum = 0;
                set<int> accset;
                accset.insert(0);
                for(auto sum:sums){
                    cursum+=sum;
                    set<int>::iterator it = accset.lower_bound(cursum - k);
                    if(it != accset.end())maxsub = max(maxsub, cursum-*it);
                    accset.insert(cursum);
                }
                res = max(res, maxsub);
            }
        }
        return res==INT_MIN?-1:res;
    }
};