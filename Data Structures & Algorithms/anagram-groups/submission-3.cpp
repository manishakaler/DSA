class Solution {
public:
    string createKeyFromArray(vector<int> charCount){
        string key = "";
        for(int i = 0; i < 26; i ++){
            key += "," + to_string(charCount[i]);
        }

        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groupStrsMap;

        vector<int>charCount(26,0);

        int n = strs.size();

        for(int i = 0; i < n ; i++){
            charCount.assign(26,0);
            string curr = strs[i];

            for(char c : curr){
                charCount[c - 'a']++;
            }
            string currKey = createKeyFromArray(charCount);
            groupStrsMap[currKey].push_back(curr);

        }
        vector<vector<string>> groupedAnagrams;
        for( auto &it: groupStrsMap){
            groupedAnagrams.push_back(it.second);
        }

        return groupedAnagrams;
    }
};
