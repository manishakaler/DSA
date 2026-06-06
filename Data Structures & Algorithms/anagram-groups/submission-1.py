class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = list()
        n = len(strs)
        added = [False] * n

        for i,s in enumerate(strs):
            row = list()
            if added[i]:
                continue
            else:
                added[i] = True
                row.append(strs[i])
                for j in range(i+1, len(strs)):
                    if len(strs[j]) != len(strs[i]):
                        continue
                    else:
                        if sorted(strs[i]) == sorted(strs[j]) and not added[j]:
                            row.append(strs[j])
                            added[j] = True
                            # strs.pop(j)
                        
                res.append(row)

        return res
                        


