#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int square = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(!i || !j || matrix[i][j] == '0'){
        			dp[i][j] = matrix[i][j] - '0';
        		}else{
        			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
        		}
        		square = max(square, dp[i][j]);
        	}
        }
        return square*square;
    }
};

int main(){
	vector<char> m = {{'1','0','1','0','0'},
					  {'1','0','1','1','1'},
					  {'1','1','1','1','1'},
					  {'1','0','0','1','0'}};
	Solution s;
	cout<<s.maximalSquare(m)<<endl;
}