# create by zbc on 2019-08-09

# dp方法：
class solution1:
    def numTrees(self, n):
        if n <= 1:
            return 1
        dp = [0 for _ in range(n+1)]

        dp[0] , dp[1] = 1, 1

        for i in range(2,n+1):
            for j in range(1,i+1):
                dp[i] += dp[j-1]+ dp[i-j]
        return dp[n]

# 卡特兰数方法
# catalan数. h(0)=h(1)=1; h(n)=C(2n,n)/(n+1); h(n)=h(n-1)*(4n-2)/(n+1);
class solution2:
    def numTrees(self, n):
        if n <= 1:
            return 1
        res = 1
        for i in range(1,n+1):
            res *= (4*i-2)/(i+1)
        return res
