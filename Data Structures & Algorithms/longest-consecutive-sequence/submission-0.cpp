class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //length batani hai - not the seq. 

        int res = INT_MIN;

        int n = nums.size();

        if(n == 0 || n == 1) return n;

        unordered_set<int> s;

        for(int i=0; i<n;i++){
            s.insert(nums[i]);
        }

        for(int num: s){
           
            if(s.find(num-1) == s.end()){ 
                //start found
                 int count = 1;
                while(s.find(num +count) != s.end()){
                     count++;
                }
               
                res = max(count, res);
            }

           
        }

        return res;


    }
};
