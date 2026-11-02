#include<vector>
class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>>timeMap;
public:
    TimeMap() {
        

    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if(timeMap.find(key)!= timeMap.end()){
            vector<pair<int,string>>& keyVault= timeMap[key];
            int keyVaultSize = keyVault.size();
            int left = 0;
            int right = keyVaultSize -1;
            int mid;
            while(left <= right){
                mid = left + (right - left)/2;
                if(keyVault[mid].first <= timestamp){
                    res = keyVault[mid].second;
                    left = mid + 1;
                }

                if(keyVault[mid].first > timestamp){
                    right = mid - 1 ;
                }

            }

            
        }

        return res;
    }
};
