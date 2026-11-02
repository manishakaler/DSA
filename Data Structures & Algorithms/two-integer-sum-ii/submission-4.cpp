class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();

         for(int i = 0; i < n ; ++i){
            int left = i+1;
            int right = n-1;
            int rem = target - numbers[i];
            while(left <= right){
                int mid = left + (right - left)/2;
                if(numbers[mid] == rem && i != mid){
                    return {i+1,mid+1};
                }

                if(numbers[mid] < rem){
                    left = mid + 1;
                } 
                if(numbers[mid] > rem) {
                    right = mid -1;
                }
            }
         }

         return {-1,-1}; 
    }
};
