# Created by 庄博城 on 2019-08-04.

class solution:
    def calculateMinimumHP(self, dungeon):
        # 这里考虑自底向上dp，最终目的为在到达右下角时保证血值为1，
        # dp[i][j] 表示进入第i行第j列的房间前所需要的最少的血量

        if not dungeon:
            return 0

        m, n = len(dungeon), len(dungeon[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i == m-1 and j == n-1:
                    dp[i][j] = 1 - dungeon[i][j]
                elif i == m-1:
                    dp[i][j] = dp[i][j+1] - dungeon[i][j]
                elif j == n-1:
                    dp[i][j] = dp[i+1][j] - dungeon[i][j]
                else:
                    dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]
                # 判断小于等于零的情况， 该情况为dungeon[i][j]不扣血，所以进入该房间只需要1血值
                if dp[i][j]<=0:
                    dp[i][j] = 1
        return dp[0][0]