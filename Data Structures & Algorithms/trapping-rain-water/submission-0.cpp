class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <=2) return 0;

        int trappedWater = 0;
        int left = 0;
        int right = n - 1;
        int leftMax = height[left], rightMax = height[right];

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                trappedWater+= leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
            }
        }
        
        return trappedWater;

    }
};
