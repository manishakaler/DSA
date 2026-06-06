class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> idxMap;
        int n = s.length();
        int maxLen = 0;
        int startIdx = 0;
        for(int i = 0; i < n; i++ ){

            if(idxMap.find(s[i])!= idxMap.end()){ //duplicate encountered
                startIdx = max(startIdx, idxMap[s[i]] + 1); // why
            }

            idxMap[s[i]] = i ;
            maxLen = max(maxLen, i - startIdx + 1);
        }

        return maxLen;
    }
};
