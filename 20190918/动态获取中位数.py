# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.smaller_arr = []
        self.larger_arr = []

    def heap_insert(self, arr, num, f):
        arr.append(num)
        num_index = len(arr)-1
        while num_index!=0 and int((num_index-1)/2)>=0 and f(arr[num_index], arr[int((num_index-1)/2)]):
            arr[num_index], arr[int((num_index-1)/2)] = arr[int((num_index-1)/2)], arr[num_index]
            num_index = int((num_index-1)/2)

    def get_top(self, arr):
        return arr[0]

    def __cmp_greater(self, x, y):
        if x>y:
            return True

    def __cmp_lower(self, x, y):
        if x<y:
            return True

    def pop_top(self, arr, f):
        temp = arr[-1]
        arr.pop()
        num_index = 0
        if len(arr) == 0:
            return []
        arr[num_index] = temp
        # adjust
        while num_index<len(arr):
            if num_index*2+1 < len(arr) <= num_index*2+2:
                if f(arr[num_index*2+1], arr[num_index]):
                    arr[num_index], arr[num_index*2+1] = arr[num_index*2+1], arr[num_index]
                    num_index = num_index*2+1
                else:
                    break
            elif num_index*2+1 >= len(arr):
                break
            elif num_index*2+2 < len(arr):
                if f(arr[num_index*2+1], arr[num_index]) or f(arr[num_index*2+2], arr[num_index]):
                    if f(arr[num_index * 2 + 2], arr[num_index * 2 + 1]):
                        arr[num_index], arr[num_index * 2 + 2] = arr[num_index * 2 + 2], arr[num_index]
                        num_index = num_index * 2 + 2
                    else:
                        arr[num_index], arr[num_index * 2 + 1] = arr[num_index * 2 + 1], arr[num_index]
                        num_index = num_index * 2 + 1
                else:
                    break

    def Insert(self, num):
        len_s = len(self.smaller_arr)
        len_l = len(self.larger_arr)

        if len_s == 0 and len_l == 0:
            self.larger_arr.append(num)
            return
        elif len_s == 0 and len_l == 1:
            if num >= self.larger_arr[0]:
                self.smaller_arr.append(num)
            else:
                self.smaller_arr.append(self.larger_arr[0])
                self.larger_arr[0] = num
            return
        elif len_s == 1 and len_l == 0:
            if num >= self.smaller_arr[0]:
                self.larger_arr.append(self.smaller_arr[0])
                self.smaller_arr[0] = num
            else:
                self.larger_arr.append(num)
            return

        if len_s >= len_l:
            if num > self.get_top(self.smaller_arr):
                self.heap_insert(self.larger_arr, self.get_top(self.smaller_arr), f=self.__cmp_greater)
                self.pop_top(self.smaller_arr, f=self.__cmp_lower)
                self.heap_insert(self.smaller_arr, num, f=self.__cmp_lower)
            else:
                self.heap_insert(self.larger_arr, num, f=self.__cmp_greater)
        elif len_l > len_s:
            if num < self.get_top(self.larger_arr):
                self.heap_insert(self.smaller_arr, self.get_top(self.larger_arr), f=self.__cmp_lower)
                self.pop_top(self.larger_arr, f=self.__cmp_greater)
                self.heap_insert(self.larger_arr, num, f=self.__cmp_greater)
            else:
                self.heap_insert(self.smaller_arr, num, f=self.__cmp_lower)

    def GetMedian(self):
        len_s = len(self.smaller_arr)
        len_l = len(self.larger_arr)
        if len_s == len_l:
            return (self.get_top(self.smaller_arr) + self.get_top(self.larger_arr))/2
        elif len_s > len_l:
            return self.get_top(self.smaller_arr)
        else:
            return self.get_top(self.larger_arr)

s = Solution()
for i in [5,2,3,4,1,6,7,0,8]:
    s.Insert(i)
    print(s.GetMedian())