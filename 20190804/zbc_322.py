# Created by 庄博城 on 2019-08-04.

class solution:
    def coinChang(self, coins, amount):

        if amount == 0:
            return 0
        
        if not coins or min(coins) > amount:
            return -1

        dp = [0 for _ in range(amount+1)]

        for coin in coins:
            if coin <= amount:
                dp[coin] = 1
        
        for i in range(1, amount+1):
            if dp[i]:
                continue
            min_ = float('inf')
            for coin in coins:
                if i - coin >=0:
                    min_ = min(min_, dp[i-coin] + 1)
            dp[i] = min_
        return -1 if dp[-1] == float('inf') else dp[-1]