class Solution {
public:
    bool isAnagram(string s, string t) {
        //time complexity - O(ns + nt), space - O(1) //only 26 char
        int ns = s.length(), nt = t.length();

        if(ns!=nt) return false;

        if(ns == 0 && ns == nt) return true;

        vector<int> freqS(26,0);
   


        for(int i = 0; i<ns; i++){
            freqS[s[i] - 'a']++;
            freqS[t[i] - 'a']--;
        } 
      
        for(int x: freqS) {
            if(x>0) 
                return false;
        }

        return true;

    }
};
