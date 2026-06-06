class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int start = 0, end = n-1;
        int maxArea = 0;

        while(start < end){

            int currArea = (end - start) * min(heights[start], heights[end]);

            maxArea = max(maxArea, currArea);

            if(heights[end] > heights[start]){
                start++;
            }else {
                end--;
            }

        }

        return maxArea;
    }
};
