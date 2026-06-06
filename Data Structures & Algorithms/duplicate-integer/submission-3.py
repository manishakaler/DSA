class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        pair = {}
        for x in nums:
            if x in pair:
                return True
            else:
                pair[x] = True
        
        return False