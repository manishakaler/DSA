class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        if(n <=1) return n;

        vector<int>freqMap(26,0);
        int left = 0;
        int maxFreq = 0;
        int ml = 0;
        for(int right = 0; right <n; ++right){
            freqMap[s[right]-'A']++;

            maxFreq = max(maxFreq,freqMap[s[right]-'A']);

            while(right - left + 1 - maxFreq > k){
                freqMap[s[left]-'A']--;
                left++;
            }

            ml = max(ml, right - left + 1);

        }

        return ml;

    }
};
