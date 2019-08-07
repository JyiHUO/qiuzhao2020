# create by zbc on 2019-08-07

from collections import deque
class solution:
    def shortestSubarray(self, A, K):
        length = len(A) + 1
        left = 0
        count = 0
        q = deque()
        for right in range(len(A)):
            count += A[right]
            if A[right]<0:
                tmp = A[right]
                j = right
                while tmp < 0 and j>=0:
                    j -= 1
                    tmp += A[j]
                j += 1
                while left >= j and left<=right:
                    count -= A[left]
                    left += 1
                while q and j <= q[-1][0]:
                    q.pop()
                q.append((j,right))
            
            while count >= K and left<=right:
                length = min(length, right-left+1)
                count -= A[left]
                left += 1
                while q and left>=q[0][0]:
                    a, b = q.popleft()
                    while left>=a and left<=b:
                        count -= A[left]
                        left += 1
        return -1 if length == len(A) + 1 else length