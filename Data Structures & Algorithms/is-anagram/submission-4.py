class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False

        freqMap = dict()
               
        for i in s:
            if i not in freqMap:
                freqMap[i] = 1
            else:
                freqMap[i] += 1
            
        for j in t:
            if j not in freqMap:
                return False
            else:
                if freqMap[j] == 0:
                    return False
                else:
                    freqMap[j] -= 1

        return True