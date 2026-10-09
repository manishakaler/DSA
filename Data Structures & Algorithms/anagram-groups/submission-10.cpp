class Solution {
public:
    string createKeyFromInput(string str){
        int charArr[26] = {0};
        string key="";
        for(char c : str){
            charArr[c - 'a']++;
        }

        for(int val: charArr){
            key+=to_string(val)+",";
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a key based on char count - 1001 -- out of 26
        unordered_map<string,vector<string>>wordKeyMap;

        for(const string &word: strs){
            string wordKey = createKeyFromInput(word);
            //cout<<"key: "<<wordKey<<endl;
            wordKeyMap[wordKey].push_back(word);
        }

        vector<vector<string>>response;

        for(auto &entry: wordKeyMap){
            response.push_back(entry.second);
        }

        return response;

    }
};
