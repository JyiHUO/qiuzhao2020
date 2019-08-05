# create by 庄博城 on 2019-08-05

class solution:
    def largestRectangleArea(self, heights):
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
