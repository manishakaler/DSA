class Solution {
public:
    bool isAnagram(string s, string t) {
        //time complexity - O(n), space - O(n)
        int ns = s.length(), nt = t.length();

        if(ns!=nt) return false;

        if(ns == 0 && ns == nt) return true;

        unordered_map<char,int> freqS;

        for(char c: s) freqS[c]++;

        for(char d: t){
            if(freqS.find(d) == freqS.end()) return false;

            freqS[d]--;
            if(freqS[d] == 0) freqS.erase(d);
        }

        return freqS.size() == 0 ;

    }
};
