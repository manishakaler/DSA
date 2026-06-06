class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [1] * n
        suf = [1] * n

        for i,x in enumerate(nums):
            if i+1 <n:
                pre[i+1] = pre[i] * x
        
        for j,y in enumerate(reversed(nums), start = 1):
                if n-j-1 >=0:
                    suf[n-j-1] = suf[n-j] * y

        print(f"prefix: {pre}")
        print(f"suf: {suf}") 

        res = list()

        for i in range(n):
            res.append(pre[i] * suf[i])

        return res