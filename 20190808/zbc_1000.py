# create by zbc on 2019-08-08

# dfs 版本会超时
class solution:
    def mergeStones(self, stones,K):
        n = len(stones)
        inf = float('inf')
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]

        def dp(i, j, m):
            if (j - i + 1 - m) % (K - 1):
                return inf
            if i == j:
                return 0 if m == 1 else inf
            if m == 1:
                return dp(i, j, K) + prefix[j + 1] - prefix[i]
            return min(dp(i, mid, 1) + dp(mid + 1, j, m - 1) for mid in range(i, j, K - 1))
        res = dp(0, n - 1, 1) #dp（i，j，k）代表第i到j位置想要合并成k个的最小代价
        return res if res < inf else -1 

# dp 版本
    class solution_dp:
        def mergeStones(self, stones,K):
            n = len(stones)
            if (n-1) % (K-1):
                return -1
            prevSum = [0 for _ in range(n+1)]
        
            dp = [[0 for _ in range(n)]for _ in range(n)]
            for i in range(n):
                prevSum[i+1] = prevSum[i] + stones[i]
                dp[i][i] = stones[i]
        
            for j in range(1,n):
                for i in range(j-1,-1,-1):
                    dp[i][j] = dp[i][i] + dp[i+1][j]
                    for mid in range(i+K-1,j,K-1):
                        dp[i][j] = min(dp[i][j], dp[i][mid]+dp[mid+1][j])
                    if not (j-i)%(K-1):
                        dp[i][j] += prevSum[j+1] - prevSum[i]
            return dp[0][n-1] - prevSum[n]
    