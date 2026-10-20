class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if(n <= 1) return n;

        unordered_set<char>idxSet;
        int left = 0;
        int maxl = 0;
        for(int right = 0; right< n; ++right){
            char c = s[right];
           
            while(idxSet.count(c)){
                idxSet.erase(s[left]);
                left++;
            }
        

            idxSet.insert(c);
            maxl= max(maxl, right - left + 1);
        }

        return maxl;
    }
};
