class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> resp; //space - O(N)

        map<int,int> freqMap; //space - O(N)

        int maxFreq = INT_MIN;

        for(int x: nums){ //O(N)
            freqMap[x]++;
            maxFreq = max(maxFreq, freqMap[x]);
        }

        cout<<maxFreq<<endl;

        //buckets of frequency - so max size will be - maxFreq+ 1 because 0 will be wasted
        vector<vector<int>>bucketArr(maxFreq+1);

        for(auto& [value, freq]: freqMap){
            bucketArr[freq].push_back(value);
            cout<<value << " "<< freq <<" "<<endl;
        }

        for(int j = maxFreq; k > 0 && j > 0 ;  j--){

            int bucketSize = bucketArr[j].size();
            int i = 0;
            while(i<bucketSize && k > 0 ){
                resp.push_back(bucketArr[j][i]);
                
                i++;
                k--;
            }
        }
        return resp;

        // time - O(NlogN), space - O(N)
    }
};
