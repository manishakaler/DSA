class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //keep a set - if something repeats - remoe that from set - before that record the len
        int ns = s.length();
        if(ns<=1) return ns;
        unordered_set<char>seen;

       

        int maxLen = 0;
        int left = 0;

        for(int r = 0; r < ns; r++){
            while(seen.count(s[r])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[r]);
            maxLen = max(maxLen, r - left + 1);
        }
        return maxLen;

    }
};
