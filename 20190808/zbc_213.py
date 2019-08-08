# create by zbc on 2019-08-08

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        return max(self.helper(nums[1:]),self.helper(nums[:-1]))
        
        
    def helper(self,nums):
        if not nums:
            return 0
        first, second = 0, nums[0]
        for i  in range(1,len(nums)):
            second, first = max(second, nums[i]+ first), second
        return second