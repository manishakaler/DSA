class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        res = []

        for i in range(len(nums)):
            diff = target - nums[i]
            
            for j in range(i+1, len(nums)):
                if nums[j] == diff:
                    res += [i,j]
                    break

        return res