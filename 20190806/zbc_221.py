# create by zbc on 2019-08-06

class solution:
    def maximalSquare(self, matrix):

        if not matrix:
            return 0

        m, n = len(matrix), len(matrix[0])
        length, prev = 0, 0
        dp = [0 for i in range(n)]

        for i in range(m):
            for j in range(n):
                tmp = dp[j]
                if matrix[i][j] == '1':
                    if j == 0 or i == 0:
                        dp[j] = 1
                    else:
                        dp[j] = min(dp[j],dp[j-1],prev) + 1
                    length = max(length, dp[j])
                else:
                    dp[j] = 0
                prev = tmp
        return length**2
