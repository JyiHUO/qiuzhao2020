class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        new_numbers = []
        max_l_index = -1
        max_l = -1
        for i, n in enumerate(numbers):
            temp = []
            while n > 0:
                temp.append(n % 10)
                n = int(n/10)
            temp.reverse()
            new_numbers.append((temp, i))
            if len(temp) > max_l:
                max_l = len(temp)
                max_l_index = i
        for i in range(len(new_numbers)):
            l = 0
            while len(new_numbers[i][0]) < max_l:
                new_numbers[i][0].append(new_numbers[max_l_index][0][l])
                l+=1
        res = []
        for j in sorted(new_numbers, key=lambda x:x[0]):
            res.append(numbers[j[1]])
        res = ''.join(map(str, res))
        return res

s = Solution()
print(s.PrintMinNumber([3, 32, 321]))
