# create by zbc on 2019-08-11

class Solution:
    def isBipartite(self, graph):
        n = len(graph)
        d = {}
        # 第i个点是否能上color这种颜色
        def dfs(color, i):
            if i in d:
                return d[i] == color
            d[i] = color
            for j in graph[i]:
                if not dfs(not color, j):
                    return False
            return True
        # 可能出现不连通图，所以遍历
        for i in range(n):
            if i not in d and not dfs(True,i):
                return False
        return True