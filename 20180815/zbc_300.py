class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n<=1:
            return n
        res = [nums[0]]
        
        for i in range(1, n):
            if nums[i]>res[-1]:
                res.append(nums[i])
            else:
                l, r = 0, len(res)
                while l<r:
                    mid = (l+r)//2
                    if res[mid] >= nums[i]:
                        r = mid
                    else:
                        l = mid+1
                res[l] = nums[i]
        return len(res)