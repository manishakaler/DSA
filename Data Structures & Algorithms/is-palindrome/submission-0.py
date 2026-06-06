class Solution:
    def isPalindrome(self, s: str) -> bool:
      
        s = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        n = len(s)
      

        for i in range(0,int(n/2)):
            j = n - 1 - i
            if s[i] != s[j]:
                return False

        return True