class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();          // number of rows
        int n = matrix[0].size();       // number of columns

        int total = m*n;
        int start = 0;
        int end = total-1;

        while(start<=end){
            int mid= start+(end-start)/2;
            int row = mid/n;
            int col = mid % n;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                start = mid +1 ;
                
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
};