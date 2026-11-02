#include<cctype>

class Solution {
public:
    bool isalphaNum(char c){
        return c >= 'A' && c <='Z' || c >='a' && c<='z' || c>='0' && c<='9';
    }
    bool isPalindrome(string s) {
        int n = s.length();

        if(n == 1) return true;
        
        
        int left = 0;
        int right = n-1;

        while(left < right){
            while(left<right && !isalphaNum(s[left])){
                left++;
            }
            while(right > left && !isalphaNum(s[right])){
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            } 
                left++;
                right--;
            
        }

        return true;
    }
};
