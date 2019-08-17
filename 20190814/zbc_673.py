class Solution:
    def findNumberOfLIS(self, nums):
        if not nums:
            return 0
        
        lengths = [0 for _ in range(len(nums))]
        count = [1 for _ in range(len(nums))]
        # lengths[i]所有结尾在第i位置的递增子串的最大长度
        # count[i]表示所有结尾在第i位置的递增子串中最长的子串集的个数
        for j in range(len(nums)):
            for i in range(j,-1,-1):
                if nums[i]<nums[j]:
                    if lengths[i] >= lengths[j]:
                        # 替换
                        lengths[j] = lengths[i] + 1
                        count[j] = count[i]
                    elif lengths[i] + 1 == lengths[j]:
                        # 添加
                        count[j] += count[i]
        maxlenth = max(lengths)
        return sum([count[i] if lengths[i] == maxlenth else 0 for i in range(len(count))])