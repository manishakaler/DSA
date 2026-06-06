class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        res = list()

        for i in range(1,len(numbers),1):
            val2 = target - numbers[i-1]
            print(val2)
        
            if val2 in numbers and numbers.index(val2) != i-1:
                res.append(i)
                res.append(numbers.index(val2)+1)
                break
        
        return res