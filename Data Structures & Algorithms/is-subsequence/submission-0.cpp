class Solution {
public:
    bool isSubsequence(string s, string t) {
        //two pointer approach

        int ls = s.length();
        int lt = t.length();

        if(lt < ls) return false;
        int sptr = 0;
        int tptr = 0;

        while(sptr < ls && tptr < lt){
            if(t[tptr] == s[sptr]){
                sptr++;
             
            } 
                tptr++;
            
        }

        return sptr == ls ;
    }
};