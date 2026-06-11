class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.length(), len_t = t.length();
    
        if(len_s != len_t) return false;

        int char_frequency[26]= {0};

        for(int i = 0 ; i < len_s; i++){
            char_frequency[s[i] - 'a']++;
            char_frequency[t[i] - 'a']--;
        }

        for(char c: s){
            cout<<c<<' ';
        }

        for(int val : char_frequency){
            if (val != 0) return false;
        }
        

        return true;
    }
};
