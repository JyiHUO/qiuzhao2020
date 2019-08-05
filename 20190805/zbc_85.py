#create by 庄博城 on 2019-08-05
# 这一题考虑84题解法，对于前i层的sub-matrix进行最大矩形查找
class solution:
    def helper(self,heights):
        if not heights:
            return 0
        
        stack = []
        heights = [0] + heights + [0]
        res = 0

        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                res = max(res, heights[tmp]*(i-1-stack[-1]))
            stack.append(i)
        return res
        
    def maximalRectangle(self, matrix):

        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        res = 0
        heights = [ 0 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                heights[j] = heights[j]+ 1 if  matrix[i][j] == '1' else 0
            res = max(res,self.helper(heights))
        return res

