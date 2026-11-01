class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute force - O(n^2) , first optimisation - O(rows log cols) - second optimisaton - O(log(rows*cols))
        //NOTE: to flatten a 2d matrix - loop from 0 to rows*cols and ith row = i / cols , ith cols = i % cols - divide by cols  gives row and modulo cols gives cols - cols cols cols 
        int rows = matrix.size();
        int cols = matrix[0].size();



        int left = 0;
        int right = rows*cols - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target){
                return true;
            }

            if(matrix[row][col] < target){
                left = mid + 1;
            }
            if(matrix[row][col] > target){
                right = mid - 1;
            }
        }
        

        return false;
    }
};
