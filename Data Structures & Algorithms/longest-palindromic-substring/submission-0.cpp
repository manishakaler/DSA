class Solution {
public:
    string longestPalindrome(string s) {
        //palindrome - what will you do 
        //
        int ns = s.length();
        if(ns <= 1) return s;
        int reslen = 1;
        int resIdx = 0;
        for(int i = 0; i < ns; ++i){
            int left = i;
            int right = i; //odd
            while(left >= 0 && right < ns && s[left] == s[right]){
                    left--;
                    right++;
            }

            if(reslen < right - left -1){
                reslen = right - left -1;
                resIdx = left + 1;
            }

            left = i;
            right = i+1; //even
            while(left >= 0 && right < ns && s[left] == s[right]){
                    left--;
                    right++;
            }

            if(reslen < right - left -1){
                reslen = right - left -1;
                resIdx = left + 1;
            }
        }

        return s.substr(resIdx, reslen);


    }
};
