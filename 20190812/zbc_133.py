# create by zbc on 2019-08-12
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
from collections import deque
class solution:
    def cloneGraph(self, node):

        lookup = {}  

        def bfs(node):
            if not node:
                return
            clone = Node(node.val,[])
            lookup[node] = clone
            q = deque()
            q.append(node)
            while q:
                tmp = q.popleft()
                for n in tmp.neighbors():
                    if n not in lookup:
                        lookup[n] = Node(n.val,[])
                        q.append(n)
                    lookup[tmp].neighbors.append(lookup[n])
            return clone

        def dfs(node):
            if not node:
                return
            clone = Node(node.val,[])
            if node not in lookup:
                lookup[node] = clone
            for n in node.neighbors:
                clone.neighbors.append(dfs(n))
            return clone

        return dfs(node)