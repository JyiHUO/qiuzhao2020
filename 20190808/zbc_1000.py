# create by zbc on 2019-08-08
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