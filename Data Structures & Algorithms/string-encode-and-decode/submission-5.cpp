#include<string>
class Solution {


public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        
        string res = "";
        for(int i = 0; i <n ; ++i){
            int currSize = strs[i].length();
            string delimiter= to_string(currSize) + '#';
            res+= delimiter + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        int strLen = s.length();
        if(strLen == 0) return {};
        vector<string> decodedStrs;
        int i = 0;
        while(i < strLen){
            int currStrSize = 0;
            while(s[i] != '#'){
                currStrSize = currStrSize* 10 + s[i] - '0';
               i++;
            }

            decodedStrs.push_back(s.substr(i+1,currStrSize));
            i+=currStrSize + 1;

            
        }

        return decodedStrs;
    }
};
