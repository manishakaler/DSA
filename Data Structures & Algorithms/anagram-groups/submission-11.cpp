class Solution {
   public:
    string getKey(string s) {
        string key = "";
        vector<int>freq(26,0);
        for (char c : s) {
            freq[c- 'a']++;
        }

        for(int v : freq){
            key+= ";"+ to_string(v);
        }

        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>groupAna;

        int n = strs.size();

        if(n == 1) return {{strs[0]}};

        map<string, vector<string>>gMap;

        for(int i = 0; i < n ; ++i){
            string key = getKey(strs[i]);
            gMap[key].push_back(strs[i]);
        }

        for(auto& [key, val]: gMap){
            groupAna.push_back(val);
        }

        return groupAna;
    }
};
