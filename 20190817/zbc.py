# 第二题：lc84的变形
n = int(input())
nums = list(map(int, input().split()))
nums = [0] + nums +[0]
prevSum = [0 for _ in range(n+2)]
for i in range(1,n+2):
    prevSum[i] = nums[i]+prevSum[i-1]

def fun2(nums):
    if not nums:
        return 0

    s = []
    res = 0
    for i in range(len(nums)):
        while s and nums[i]<nums[s[-1]]:
            tmp = s.pop()
            res = max(res,nums[tmp]*(prevSum[i-1]-prevSum[s[-1]]))
        s.append(i)
    return res
res = fun2(nums)
print(res)

# 第三题： 
