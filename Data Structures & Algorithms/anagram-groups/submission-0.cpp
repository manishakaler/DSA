class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time complexity - O(n*n) , sp

        vector<vector<string>> grp;

        int n = strs.size();

        if(n == 0) return grp;

        unordered_map<string,vector<string>> res;

        for(int i = 0; i < n; i++){
          vector<int> count(26,0);
          
          for(char s: strs[i]){
             count[s - 'a']++;
          }

            string key = to_string(count[0]);

            for(int j = 1; j < 26; j++){
                key+= ","+ to_string(count[j]);
            }

            res[key].push_back(strs[i]);
        }

        for(const auto& pair : res){
            grp.push_back(pair.second);
        }

        return grp;

    }
};
