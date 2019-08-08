# create by zbc on 2019-08-07

class solution:
    def canFinish(self, numCourses, prerequisites):

        if not prerequisites:
            return True

        in_degrees = [0 for _ in range(numCourses)]

        adj = [set() for _ in range(numCourses)]
        for first, second in prerequisites:
            in_degrees[first] += 1
            adj[second].add(first)
        
        queue = []
        for i in range(len(in_degrees)):
            if in_degrees[i] == 0:
                queue.append(i)
        
        cnt = 0
        while queue:
            cur = queue.pop() 
            cnt += 1
            for course in adj[cur]:
                in_degrees[course] -= 1
                if in_degrees[course] == 0:
                    queue.append(course)
        return cnt == numCourses

            