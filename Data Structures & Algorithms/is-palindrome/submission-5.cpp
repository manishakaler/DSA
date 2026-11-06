class Solution {
public:
    bool isAlnum(char c){
        return c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9';
    }
    bool isPalindrome(string s) {
        int ns = s.length();
        string p;
        for(int i = 0; i <ns; ++i){
            if(isAlnum(s[i])){
                p+=tolower(s[i]);
            }
        }

        int left = 0;
        int right = p.length() - 1;

        while(left <= right){
            if(p[left] != p[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
