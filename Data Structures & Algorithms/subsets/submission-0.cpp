class Solution{

public:
    void backtrackArrForSubsets(vector<int>& nums, vector<int>&current, vector<vector<int>>& results, int index, int size){
        if(index ==size){
           results.push_back(current);
           return;
        }

        //insert i-th element
        current.push_back(nums[index]);
       
        backtrackArrForSubsets(nums, current, results, index+1, size);

        //skip the i-th element
        current.pop_back();
       
        backtrackArrForSubsets(nums,current,results, index+1, size);

    }
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> subsetResults;
        vector<int> currentSubset;
        backtrackArrForSubsets(nums, currentSubset,subsetResults, 0,n);

        return subsetResults;

        //time complexity : O(2^n * n) - 2^n times recursion is called - and O(n) for copying/inserting current 
        //space complexity : auxillary - O(n) for the stack - and output is O(n*2^n) - total subsets - 2^n with each subset having upto n elements so O(n* 2^n)
    }

};