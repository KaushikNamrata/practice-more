class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        bool rowZero = false;         // to check if first row has any zero
        bool colZero = false;         // to check if first column has any zero

        // STEP 1: Check if first row contains any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }

        // STEP 1: Check if first column contains any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }

        // STEP 2: Use first row & first column as markers
        // If matrix[i][j] == 0, mark its row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // mark row
                    matrix[0][j] = 0;   // mark column
                }
            }
        }

        // STEP 3: Set matrix cells to zero using markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // STEP 4: If first row had zero, make entire first row zero
        if (rowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // STEP 4: If first column had zero, make entire first column zero
        if (colZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};