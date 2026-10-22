class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        //if(n==2) return nums;

        vector<int>preMul(n);
        vector<int>suffMul(n);

        preMul[0]=1;
        suffMul[n-1]=1;

        for(int i = 1, j = n-2 ; i < n && j >= 0 ; ++i, --j){
            preMul[i] = nums[i-1] * preMul[i-1];

            suffMul[j] = nums[j+1] * suffMul[j+1];
        }

        vector<int>res(n);
        for(int k = 0; k<n; ++k){
            res[k] = preMul[k] * suffMul[k];
        }

        return res;

    }
};
