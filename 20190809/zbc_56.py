# create by zbc on 2019-08-09

class solution:
    def marge(self,intervals):
        if not intervals:
            return []

        s = 0
        for i in range(1,len(intervals)):
            if intervals[s][1] >= intervals[i][0]:
                intervals[s][1] = max(intervals[s][1], intervals[i][1])
                intervals[i] = []
            else:
                s = i
        return [interval for interval in intervals if interval]