class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto s: strs){
            enc += to_string(s.length()) + '#' + s ;
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> resp;
        int prevStrEnd = -1;
        for(int i = 0; i< s.length(); i++){
            if(s[i] == '#'){
                int sizeOfStr = stoi(s.substr(prevStrEnd + 1, i));
                prevStrEnd= i + sizeOfStr;
                string str = "";
                while(sizeOfStr!=0){
                    i++;
                    str+= s[i];
                    sizeOfStr--;
                    
                }

                // if(str != ""){
                    resp.push_back(str);
                // }
            }
        }

        return resp;
    }
};
