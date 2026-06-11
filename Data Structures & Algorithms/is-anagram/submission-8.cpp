class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.length(), len_t = t.length();
    
        if(len_s != len_t) return false;

        unordered_map<char,int> freq_map_s;
        unordered_map<char,int> freq_map_t;

        for(int i =0 ; i < len_s; i++){
            freq_map_s[s[i]]++;
            freq_map_t[t[i]]++;
        }

        if(freq_map_s == freq_map_t){
            return true;
        }

        return false;
    }
};
