# create by zbc on 2019-08-17
class solution:
    def maxCoins(self, nums):

        if not nums:
            return 0
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(n)]

        for j in range(2,n):
            for i in range(j-2,-1,-1):
                for k in range(i+1,j):
                    # dp[i][j] 表示第i到j子数组能够获得的最大coins
                    # 保留i和j，因为左右两边的哨兵不能被戳
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j])
        return dp[0][n-1]