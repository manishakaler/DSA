class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # pair = dict()
        seen = set()
        for x in nums:
            if x in seen:
                return True
            seen.add(x)
        
        return False