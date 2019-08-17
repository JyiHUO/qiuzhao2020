class Solution:
    def majorityElement(self, nums):
        x, y = 0, 0
        cx, cy = 0, 0
        for n in nums:
            if (cx == 0 or x == n ) and y != n:
                cx += 1
                x = n
            elif cy == 0 or y == n:
                cy += 1
                y = n
            else:
                cy -= 1
                cx -= 1
        cnt = 0
        res = []
        for n in nums:
            if x == n:
                cnt += 1
        if cnt > len(nums)//3:
            res.append(x)
        cnt = 0
        for n in nums:
            if y == n:
                cnt += 1
        if cnt > len(nums)//3 and x != y:
            res.append(y)
            
        return res