# create by zbc on 2019-08-06

# 超时
# python没有treeset数据结构实现，\
# 在helper函数中数组搜索花费时间不能降到nlogn级别 \

class Solution:
    def maxSumSubmatrix(self, matrix, k):
        
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        
        res = -float('inf')
        
        for j in range(n):
            dp = [0 for _ in range(m)]
            
            for col in range(j,n):
                for row in range(m):
                    dp[row] += matrix[row][col]
                res = max(res,self.helper(dp,k))
        return res
                
                
                
                
    def helper(self,dp,k):
        
        res = -float('inf')
        for i in range(len(dp)):
            tmp = 0
            for j in range(i,len(dp)):
                tmp += dp[j]
                if tmp <=k and tmp>res:
                    res = tmp
        return res

