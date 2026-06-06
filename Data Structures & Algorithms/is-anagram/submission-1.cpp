class Solution {
public:
    bool isAnagram(string s, string t) {
        //time complexity - O(ns + nt), space - O(1) //only 26 char
        int ns = s.length(), nt = t.length();

        if(ns!=nt) return false;

        if(ns == 0 && ns == nt) return true;

        unordered_map<char,int> countS;
        unordered_map<char,int> countT;


        for(int i = 0; i<ns; i++){
            countS[s[i]]++;
            countT[t[i]]++;
        } 

      
        return countS == countT ;

    }
};
