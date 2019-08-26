# create by zbc on 2019-08-26
class solution:
    def adjust(self,nums,p):
        n = len(nums)
        maxid = p
        while p<(n//2):
            c = p*2
            if c<n and nums[c]>nums[maxid]:
                maxid = c
            if c+1 < n and nums[c+1]>nums[maxid]:
                maxid = c+1
            if maxid == p:
                break
            nums[p], nums[maxid] = nums[maxid], nums[p]
            p = maxid
    def create(self,nums):
        for i in range(len(nums)//2-1,-1,-1):
            self.adjust(nums,i)
    def topK(self,nums,k):
        if len(nums)<k:
            return []
        heap = nums[:k]
        self.create(heap)
        for i in range(k,len(nums)):
            if heap[0]>nums[i]:
                heap[0] = nums[i]
                self.adjust(heap,0)
        return heap
s = solution()
res = s.topK([2,3,14,5,67,27,9],4)
print(res)

